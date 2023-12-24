#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        //TC O(n), SC O(n)
        vector<set<pair<int, int>>> top3(scores.size(), set<pair<int, int>>());

        for(auto &edge:edges){
            auto &s0 = top3[edge[0]];
            auto &s1 = top3[edge[1]];
            s0.emplace(scores[edge[1]], edge[1]);
            s1.emplace(scores[edge[0]], edge[0]);
            if(s0.size() > 3){
                s0.erase(s0.begin());
            }
            if(s1.size() > 3){
                s1.erase(s1.begin());
            }
        }

        int res = -1;

        for(auto &edge:edges){
            for(auto &p0:top3[edge[0]]){
                for(auto &p1:top3[edge[1]]){
                    if(p0.second != p1.second && p0.second != edge[1] && p1.second != edge[0]){
                        res = max(res, p0.first + p1.first + scores[edge[0]] + scores[edge[1]]);
                    }
                }
            }
        }
        return res;
    }
};