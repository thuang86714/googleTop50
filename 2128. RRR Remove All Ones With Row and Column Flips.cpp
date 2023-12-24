#include <vector>
using namespace std;

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        //TC O(m*n), SC O(1)
        int m = grid.size(), n = grid[0].size();
        for(int j = 0; j < n; j++){
            if(grid[0][j]){
                for(int i = 0; i < m; i++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        for(int i = 1; i < m; i++){
            if(grid[i][0]){
                for(int j = 0; j < n; j++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    return false;
                }
            }
        }

        return true;
    }
};