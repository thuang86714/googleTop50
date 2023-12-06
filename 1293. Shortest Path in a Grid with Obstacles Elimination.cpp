/*
You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

 

Example 1:
Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).

Example 2:
Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 40
1 <= k <= m * n
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 0
*/
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        //credit to jainkartik203, BFS
        return calStepsBFS(grid, k);
    }
private:
    vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int calStepsBFS(vector<vector<int>>& grid, int k){
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(), -1));
        queue<vector<int>> toVisit;

        toVisit.push({0, 0, 0, k});//{x, y, step, curK}
        while(!toVisit.empty()){
            auto curVec = toVisit.front();
            int x = curVec[0], y = curVec[1];
            toVisit.pop();

            if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()){
                continue;
            }

            if(x == grid.size() - 1 && y == grid[0].size() - 1){
                return curVec[2];
            }

            if(grid[x][y] == 1){
                if(curVec[3] > 0){
                    curVec[3]--;
                }else{
                    continue;
                }
            }

            if(visited[x][y] != -1 && visited[x][y] >= curVec[3]){
                continue;//avoid cycle
            }
            visited[x][y] = curVec[3];

            for(int i = 0; i < dirs.size(); i++){
                toVisit.push({x + dirs[i].first, y + dirs[i].second, curVec[2] + 1, curVec[3]});
            }            
        }
        return -1;
    }
};