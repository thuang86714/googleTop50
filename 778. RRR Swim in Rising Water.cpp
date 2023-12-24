#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        //Dij, time complexity: O(n^2*logn)
        int n = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> toVisit;
        toVisit.push({grid[0][0], 0, 0});
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        int ans = INT_MIN;
        while(!toVisit.empty()){
            auto curVec = toVisit.top();
            toVisit.pop();
            int water = curVec[0], x = curVec[1], y = curVec[2];
            ans = max(ans, water);

            if(x == n - 1 && y == n - 1){
                return ans;
            }

            visited[x][y] = true;

            for(int i = 0; i < dirs.size(); i++){
                int newX = x + dirs[i].first, newY = y + dirs[i].second;
                if(newX < 0 || newY < 0 || newX >= n || newY >= n || visited[newX][newY]){
                    continue;
                }
                toVisit.push({grid[newX][newY], newX, newY});
            }
        }
        return -1;
    }
private:
    vector<pair<int, int>> dirs{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
};

class Solution {
    //dfs, TC O(n^2logn), SC O(n^2)
public:
    int swimInWater(std::vector<std::vector<int>>& heightGrid) {
        
        int size = heightGrid.size();
        int lowerBound = heightGrid[0][0], upperBound = size * size - 1;
        
        while (lowerBound < upperBound) {
            int mid = lowerBound + (upperBound - lowerBound) / 2;
            if (isPathValid(heightGrid, mid))
                upperBound = mid;
            else
                lowerBound = mid + 1;
        }
        
        return lowerBound;
    }

private:
    bool isPathValid(std::vector<std::vector<int>>& heightGrid, int waterHeight) {
        //DFS,
        int size = heightGrid.size();
        std::vector<std::vector<int>> visited(size, std::vector<int>(size, 0));
        std::vector<int> direction({-1, 0, 1, 0, -1});
        return dfs(heightGrid, visited, direction, waterHeight, 0, 0, size);
    }

    bool dfs(std::vector<std::vector<int>>& heightGrid, std::vector<std::vector<int>>& visited, 
             std::vector<int>& direction, int waterHeight, int row, int col, int size) {
        visited[row][col] = 1;

        for (int i = 0; i < 4; ++i) {
            int newRow = row + direction[i];
            int newCol = col + direction[i + 1];

            if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size &&
                visited[newRow][newCol] == 0 && heightGrid[newRow][newCol] <= waterHeight) {
                if (newRow == size - 1 && newCol == size - 1) 
                    return true;
                if (dfs(heightGrid, visited, direction, waterHeight, newRow, newCol, size)) 
                    return true;
            }
        }
        
        return false;
    }
};