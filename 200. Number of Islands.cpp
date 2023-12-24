#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    counter++;
                    findIslandDFS(grid, i, j);
                }
            }
        }
        return counter;
    }
private:
    vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    void findIslandDFS(vector<vector<char>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != '1'){
            return;
        }
        grid[x][y] = '0';
        for(int i = 0; i < dirs.size(); i++){
            int newX = x + dirs[i].first, newY = y + dirs[i].second;
            findIslandDFS(grid, newX, newY);
        }
    }
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        int m = grid.size(), n = m ? grid[0].size() : 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    counter++;
                    findIslandBFS(grid, i, j);
                }
            }
        }
        return counter;
    }
private:
    vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    void findIslandBFS(vector<vector<char>>& grid, int x, int y){
        queue<pair<int, int>> toVisit;
        toVisit.push({x, y});
        grid[x][y] = '0';
        while(!toVisit.empty()){
            auto [x, y] = toVisit.front();
            toVisit.pop();
            
            for(int i = 0; i < dirs.size(); i++){
                int newX = x + dirs[i].first, newY = y + dirs[i].second;
                if(newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size() || grid[newX][newY] == '0'){
                    continue;
                }
                grid[newX][newY] = '0';
                toVisit.push({newX, newY});
            }
        }
        return;
    }
};