#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({grid[0][0], 0, 0});
        vector<vector<int>> visited(n, vector<int> (n, 0));
        visited[0][0] = 1;

        while(!minHeap.empty()){
            auto curVec = minHeap.top();
            minHeap.pop();
            res = max(res, curVec[0]);
            if(curVec[1] == n - 1 && curVec[2] == n - 1){
                return res;
            }

            for(int i = 0; i < dirs.size(); i++){
                int newX = curVec[1] + dirs[i].first;
                int newY = curVec[2] + dirs[i].second;
                if(newX >= 0 && newY >= 0 && newX < n && newY < n && !visited[newX][newY]){
                    visited[newX][newY] = 1;
                    minHeap.push({grid[newX][newY], newX, newY});
                }
            }
        }
        return -1;
    }
private:
    vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};