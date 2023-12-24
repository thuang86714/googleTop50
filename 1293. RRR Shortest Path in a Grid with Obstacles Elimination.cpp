#include <vector>
#include <queue>
#include <cmath>
using namespace std;


class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        if(k >= grid.size() + grid[0].size() - 2){
            return grid.size() + grid[0].size() - 2;
        }
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> toVisit;
        toVisit.push({0, 0, 0, k});
        vector<vector<int>> visited(m, vector<int> (n, -1));

        while(!toVisit.empty()){
            auto curVec = toVisit.front();
            toVisit.pop();
            int step = curVec[0], x = curVec[1], y = curVec[2], k = curVec[3];
            if(x == m - 1 && y == n - 1){
                return step;
            }

            if(grid[x][y]){
                if(k > 0){
                    k--;
                }else{
                    continue;
                }
            }

            if(visited[x][y] != -1 && visited[x][y] >= k){
                continue;
            }
            visited[x][y] = k;

            for(int i = 0; i < dirs.size(); i++){
                int newX = x + dirs[i].first, newY = y + dirs[i].second;
                if(newX < 0 || newY < 0 || newX >= m || newY >= n){
                    continue;
                }
                toVisit.push({step + 1, newX, newY, k});
            }
        }
        return -1;
    }
private:
    vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};