/*
Given a list of strings dict where all the strings are of the same length.

Return true if there are 2 strings that only differ by 1 character in the same index, otherwise return false.

 

Example 1:

Input: dict = ["abcd","acbd", "aacd"]
Output: true
Explanation: Strings "abcd" and "aacd" differ only by one character in the index 1.
Example 2:

Input: dict = ["ab","cd","yz"]
Output: false
Example 3:

Input: dict = ["abcd","cccc","abyd","abab"]
Output: true
 

Constraints:

The number of characters in dict <= 105
dict[i].length == dict[j].length
dict[i] should be unique.
dict[i] contains only lowercase English letters.
 

Follow up: Could you solve this problem in O(n * m) where n is the length of dict and m is the length of each string.
*/
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


class Node {
    //credit to pratickkejriwal, Time & Space complexity is O(n^2 * m)
    public:
    Node* children[26];

    Node() {
        memset(children, NULL, sizeof(children));
    }

    Node* get(char ch) {
        return children[ch - 'a'];
    }

    void put(char ch, Node* node) {
        children[ch - 'a'] = node;
    }

    bool contains(char ch) {
        return children[ch - 'a'] != NULL;
    }

    bool find(int idx, string& s, bool mismatch = false) {
        if (idx == s.size())
            return mismatch;
        if (contains(s[idx]) and get(s[idx])->find(idx+1, s, mismatch))
            return true;
        if (mismatch)
            return false;
        for(int iter = 0; iter < 26; iter++) {
            char c = iter + 'a';
            Node* node = children[iter];
            if (node != NULL and s[idx] != c and node->find(idx+1, s, true))
                return true;
        }
        return false;
    }
};

class Trie {
    public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string& s) {
        Node* curr = root;
        for(char c : s) { 
            if (!curr->contains(c)) 
                curr->put(c, new Node());
            curr = curr->get(c);
        }
    }

    bool find(string& s) {
        return root->find(0, s);
    }
};

class Solution {
    public:
    bool differByOne(vector<string>& dict) {
        Trie* trie = new Trie();
        for(string &s : dict)
            trie->insert(s);
        
        for(string &s : dict)
            if (trie->find(s))
                return true;

        return false;
    }
};

class Solution {
public:
    bool differByOne(vector<string>& dict) {
        //credit to pratickkejriwal, Rabin-Karp Hashing Algo
        int base = 26, mod = 1e6+7;
        unordered_map<int, int> hashes;
        {
            int i = 0;
            for(string &word:dict){
                hashes[getHash(word, base, mod)] = i++;
            }
        }

        for(string &word:dict){
            int hash = getHash(word, base, mod);
            int mul = 1;
            for(int i = word.size() - 1; i >= 0; i--){
                for(char c = 'a'; c <= 'z'; c++){
                    int cur = (hash - (mul*word[i])%mod + (mul*c)%mod)%mod;
                    if(cur < 0){
                        cur += mod;
                    }
                    if(hash == cur){
                        continue;
                    }
                    if(hashes.find(cur) != hashes.end() && equal(word, dict[hashes[cur]], i)){
                        return true;
                    }
                }
                mul = (base*mul)%mod;
            }
        }
        return false;
    }
private:
    int getHash(string &s, int base, int mod){
        int hash = 0;
        for(char c:s){
            hash = ((hash*base)%mod + c)%mod;
        }
        return hash;
    }

    bool equal(string &s1, string &s2, int skip){
        for(int i = 0; i < s1.size(); i++){
            if(i == skip){
                continue;
            }
            if(s1[i] != s2[i]){
                return false;
            }
        }
        return true;
    }
};

class Solution {
 public:
  auto differByOne(vector<string>& dict) -> bool {
      //credit to ianpan870102, TC O(n^2*m), SC O(1)
    const int M = dict.size();

    for (int i = 0; i < M; ++i) {
      for (int j = i + 1; j < M; ++j) {
        if (is_different_by_one(dict[i], dict[j])) {
          return true;
        }
      }
    }

    return false;
  }

 private:
  auto is_different_by_one(const string& a, const string& b) -> bool {
    if (a.length() != b.length()) return false;

    int different_count{0};
    for (int i = 0, n = a.length(); i < n; ++i) {
      if (a[i] != b[i]) ++different_count;
      if (different_count > 1) return false;
    }

    return different_count == 1;
  }
};

class Solution {
public:
    bool differByOne(vector<string>& dict) {
        //TLE
        unordered_set<string> dictSet{dict.begin(), dict.end()};

        for(string word:dict){
            for(int i = 0; i < word.size(); i++){
                char temp = word[i];
                for(int j = 0; j < 26; j++){
                    word[i] = 'a' + j;
                    if(word[i] != temp && dictSet.count(word)){
                        return true;
                    }
                }
                word[i] = temp;
            }
        }

        return false;
    }
};