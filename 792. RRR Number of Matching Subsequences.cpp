#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<pair<int, int>> charTracker[128];
        for(int i = 0; i < words.size(); i++){
            charTracker[words[i][0]].push_back({i, 1});
        }

        for(char c:s){
            auto advance = charTracker[c];
            charTracker[c].clear();    
            for(auto &[wordsIdx, posIdx]:advance){
                charTracker[words[wordsIdx][posIdx++]].push_back({wordsIdx, posIdx});
            }
        }

        return charTracker[0].size();
    }
};