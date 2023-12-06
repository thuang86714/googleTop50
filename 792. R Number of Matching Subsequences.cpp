#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        //credit to StefanPochmann, similar to hiepit's solution
        /*
        TC O(s.size() + m), where m is sum of words[i].size()
        SC O(1)
        */
        vector<pair<int, int>> waiting[128];
        for (int i = 0; i < words.size(); i++){
            waiting[words[i][0]].emplace_back(i, 1);
        }
        
        for (char c : S) {
            auto advance = waiting[c];
            waiting[c].clear();
            for (auto &[wordIdx, posIdx] : advance){//when posIdx >= words[wordIdx].size(), postIdx == NULL
                waiting[words[wordIdx][posIdx++]].emplace_back(wordIdx, posIdx);
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
