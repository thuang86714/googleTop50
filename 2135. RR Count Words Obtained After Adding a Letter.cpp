#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Trie{
private:
  unordered_map<char, Trie*>next;
  bool isEnd = false;
public:
  Trie(){

  }
  void insert(string word){
    Trie *node = this;
    for(char c:word){
      if(!node->next[c]){
        node->next[c] = new Trie();
      }
      node = node->next[c];
    }
    node->isEnd = true;
  }
  bool exist(string word){
    Trie *node = this;
    for(char c:word){
      if(!node->next[c]){
        return false;
      }
      node = node->next[c];
    }
    return node->isEnd;
  }
};
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        Trie root;
        for(string word:startWords){
            string temp = word;
            sort(temp.begin(), temp.end());
            root.insert(temp);
        }
        int ans = 0;
        for(string word:targetWords){
            sort(word.begin(), word.end());
            for(int i = 0; i < word.size(); i++){
                string temp = word.substr(0, i) + word.substr(i + 1);
                if(root.exist(temp)){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }

};

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> dict;
        for(string word:startWords){
            string temp = word;
            sort(temp.begin(), temp.end());
            dict.insert(temp);
        }
        int ans = 0;
        for(string word:targetWords){
            sort(word.begin(), word.end());
            for(int i = 0; i < word.size(); i++){
                string temp = word.substr(0, i) + word.substr(i + 1);
                if(dict.count(temp)){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};