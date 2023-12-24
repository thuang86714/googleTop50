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
        return findPathBFS(grid, k);
    }
private:
    vector<pair<int, int>> dirs{{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    bool boundaryCheck(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()){
            return false;
        }
        return true;
    }
    int findPathBFS(vector<vector<int>>& grid, int k){
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<vector<int>> toVisit;
        toVisit.push({0, 0, 0, k});
        while(!toVisit.empty()){
            auto curVec = toVisit.front();
            toVisit.pop();
            int steps = curVec[0], x = curVec[1], y = curVec[2];
            if(x == m - 1 && y == n - 1){
                return steps;
            }
            if(grid[x][y] == 1){
                if(curVec[3] > 0){
                    curVec[3]--;
                }else{
                    continue;
                }
            }

            if(visited[x][y] != -1 && visited[x][y] >= curVec[3]){
                continue;
            }
            visited[x][y] = curVec[3];

            for(int i = 0; i < dirs.size(); i++){
                int newX = x + dirs[i].first;
                int newY = y + dirs[i].second;
                if(boundaryCheck(grid, newX, newY)){
                    toVisit.push({steps + 1, newX, newY, curVec[3]});
                }
            }
        }
        return -1;
    }
};