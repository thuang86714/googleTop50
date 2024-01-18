#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    //credit to coding_menance
    {
        map<int,int> lost;
        for (auto m : matches)
        {
            if (!lost.count(m[0])) lost[m[0]] = 0;
            lost[m[1]]++;
        }
        
        vector<int> zero, ones;
        for (auto[k,l] : lost)
        {
            if (l == 0) zero.push_back(k);
            if (l == 1) ones.push_back(k);
        }
        
        return {zero,ones};
    }
};


class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        //TC O(nlogn), SC O(n)
        vector<vector<int>> res;
        unordered_map<int, int> loseCount;
        unordered_set<int> winCount;
        for(auto &match:matches){
            winCount.insert(match[0]);
        }
        for(auto &match:matches){
            winCount.erase(match[1]);
            loseCount[match[1]]++;
        }
        vector<int> winVec, loseVec;
        for(auto &win:winCount){
            winVec.push_back(win);
        }
        sort(winVec.begin(), winVec.end());
        res.push_back(winVec);
        for(auto &lose:loseCount){
            if(lose.second == 1){
                loseVec.push_back(lose.first);
            }
        }
        sort(loseVec.begin(), loseVec.end());
        res.push_back(loseVec);
        return res;
    }
};