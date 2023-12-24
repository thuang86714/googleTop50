#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct Trie{
    int count;
    unordered_map<char, Trie*>next;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for(string word:words){
            insert(word);
        }

        vector<int> ans;
        for(string word:words){
            ans.push_back(prefixCount(word));
        }
        return ans;
    }
private:
    Trie root;
    void insert(string s){
        auto node= &root;
        for(char c:s){
            if(!node->next[c]){
                node->next[c] = new Trie();
            }
            node->next[c]->count++;
            node = node->next[c];
        }
    }

    int prefixCount(string s){
        auto node = &root;
        int ans = 0;
        for(char c:s){
            ans += node->next[c]->count;
            node = node->next[c];
        }
        return ans;
    }
};