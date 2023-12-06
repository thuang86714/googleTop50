#include <unordered_set>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Trie{
    bool isEnd = false;
    unordered_map<char, Trie*> next;
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
        for(string &word:startWords){
            sort(word.begin(), word.end());
            root.insert(word);
        }
        int counter = 0;
        for(string &word: targetWords){
            sort(word.begin(), word.end());
            for(int i = 0; i < word.size(); i++){
                string temp = word.substr(0, i) + word.substr(i + 1);
                if(root.exist(temp)){
                    counter++;
                    break;
                }
            }
        }
        return counter;
    }

};


class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        //m = startWords.size(), n = targetWords.size(), k = avg len of all words in targetWords
        //TC O(m + n*k), SC O(m)
        unordered_set<string> dict;
        for(string &word:startWords){
            string temp = word;
            sort(temp.begin(), temp.end());
            dict.insert(temp);
        }
        int counter = 0;
        for(string &word:targetWords){
            sort(word.begin(), word.end());
            for(int i = 0; i < word.size(); i++){
                string temp = word.substr(0, i) + word.substr(i + 1);
                if(dict.count(temp)){
                    counter++;
                    break;
                }
            }
        }
        return counter;
    }
};