
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        queue<pair<int, int>> toVisit;
        toVisit.push({0, 0});

        while(!toVisit.empty()){
            auto [x, y] = toVisit.front();
            toVisit.pop();
            res.push_back(nums[x][y]);

            if(x + 1 < nums.size() && y == 0){
                toVisit.push({x + 1, y});
            }

            if(y + 1 < nums[x].size()){
                toVisit.push({x, y + 1});
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> tracker;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                tracker[i + j].push_back(nums[i][j]);
            }
        }
        vector<int> res;
        for(auto &it:tracker){
            reverse(it.second.begin(), it.second.end());
            for(int num:it.second){
                res.push_back(num);
            }
        }
        return res;
    }
};