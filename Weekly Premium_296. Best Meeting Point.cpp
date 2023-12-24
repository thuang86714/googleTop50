#include <vector>
#include <cmath>
#include <queue>
using namespace std;

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        //credit to hiepit, TC O(m*n), SC O(m*n)
        vector<int> rows, cols;
        int m = grid.size(), n = grid[0].size();
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                if(grid[i][j]){
                    rows.push_back(j);       
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    cols.push_back(i);
                }
            }
        }

        int rMedium = rows[rows.size()/2];
        int cMedium = cols[cols.size()/2];
        int ans = 0;

        for(const int &r:rows){
            ans += abs(r - rMedium);
        }
        for(const int &c:cols){
            ans += abs(c - cMedium);
        }
        
        return ans;
    }
};


class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        //BFS, TLE, TC O(n^2*m^2), SC O(m*n)
        int ans = INT_MAX;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                ans = min(ans, findDistanceBFS(grid, i, j));
            }
        }
        return ans;
    }
private:
    vector<pair<int, int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int findDistanceBFS(vector<vector<int>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size(), distanceSum = 0;
        queue<vector<int>> toVisit;
        toVisit.push({i, j, 0});
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        while(!toVisit.empty()){
            auto curVec = toVisit.front();
            toVisit.pop();
            int x = curVec[0], y = curVec[1], dis = curVec[2];
            if(x < 0 || y < 0 || x >= m || y >= n || visited[x][y]){
                continue;
            }
            if(grid[x][y]){
                distanceSum += dis;
            }

            visited[x][y] = true;
            for(int i = 0; i < dirs.size(); i++){
                int newX = x + dirs[i].first, newY = y + dirs[i].second;
                toVisit.push({newX, newY, dis+1});
            }
        }
        return distanceSum;
    }
};