/*
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
 

Constraints:

1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        //credit to StefanPochmann, similar to hiepit's solution
        vector<pair<int, int>> waiting[128];
        for (int i = 0; i < words.size(); i++){
            waiting[words[i][0]].emplace_back(i, 1);
        }
        
        for (char c : S) {
            auto advance = waiting[c];
            waiting[c].clear();
            for (auto it : advance){//it is ptr
                waiting[words[it.first][it.second++]].push_back(it);
            }
        }
        //in ascii table 0 == NULL
        return waiting[0].size();
}
};


struct Node{
    string word;
    int idx;
    Node(string word, int idx){
        this->word= word;
        this->idx = idx;
    }
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        //credit to hiepit, TC O(N+S) SC O(N)
        vector<vector<Node>> buckets(26);
        for(string word:words){
            char firstChar = word[0];
            buckets[firstChar - 'a'].emplace_back(word, 0);
        }
        int ans = 0;
        for(char c:s){
            auto curBucket = buckets[c - 'a'];
            buckets[c - 'a'].clear();
            for(auto &node:curBucket){
                node.idx++;
                if(node.idx == node.word.size()){
                    ans++;
                }else{
                    buckets[node.word[node.idx] - 'a'].push_back(node);
                }
            }
        }
        return ans;
    }
};