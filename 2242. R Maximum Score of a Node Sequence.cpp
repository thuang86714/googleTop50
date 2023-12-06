#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        //credit to lee215 and dragoljub-duric, TC O(n), SC O(n), n = edges.size()
        vector<set<pair<int, int>>> top3 (scores.size(), set<pair<int, int>>());
        
        for(vector<int>& e : edges){
            set<pair<int, int>>& s0 = top3[e[0]];
            set<pair<int, int>>& s1 = top3[e[1]];
            s0.emplace(scores[e[1]], e[1]);
            s1.emplace(scores[e[0]], e[0]);
            if(s0.size() > 3) s0.erase(s0.begin());
            if(s1.size() > 3) s1.erase(s1.begin());
        }
        
        int res = -1;
        
        for(vector<int>& e : edges)
            for(pair<int, int> p0 : top3[e[0]])
                for(pair<int, int> p1 : top3[e[1]])
                    if(p0.second != p1.second && p0.second != e[1] && p1.second != e[0])//check for overlap nodes
                        res = max(res, p0.first + p1.first + scores[e[0]] + scores[e[1]]);    
 
        return res;
    }
};