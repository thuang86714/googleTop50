#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        //credit to StefanPochman
        vector<pair<int, int>> waiting[126];
        for(int i = 0; i < words.size(); i++){
            waiting[words[i][0]].push_back({i, 1});
        }

        for(char c:s){
            auto advance = waiting[c];
            waiting[c].clear();
            for(auto &[wordsIdx, posIdx]:advance){
                waiting[words[wordsIdx][posIdx++]].push_back({wordsIdx, posIdx});
            }
        }
        return waiting[0].size();
    }
};