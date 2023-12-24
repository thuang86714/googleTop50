#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct Trie{
    unordered_map<char, Trie*> next;
    int count;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for(string word:words){
            insert(word);
        }

        vector<int>ans;
        for(string word:words){
            ans.push_back(prefixCount(word));
        }
        return ans;
    }
private:
    Trie root;
    void insert(string word){
        auto node = &root;
        for(char c:word){
            if(!node->next[c]){
                node->next[c] = new Trie();
            }
            node->next[c]->count++;
            node = node->next[c];
        }
    }

    int prefixCount(string word){
        auto node = &root;
        int ans = 0;
        for(char c:word){
            ans += node->next[c]->count;
            node = node->next[c];
        }
        return ans;
    }
};