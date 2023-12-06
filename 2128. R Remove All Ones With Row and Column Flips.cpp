#include <vector>
using namespace std;

class Solution {
public:
    bool removeOnes(vector<vector<int>>& g) {
    //credit to votrubac, TC O(m*n), SC O(1)
    for (int i = 0; i < g.size(); ++i)
        for (int j = 0; j < g[i].size(); ++j)
            if (g[i][j] ^ g[i][0] ^ g[0][j] ^ g[0][0])
                return false;
    return true;
}
};

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        //TC O(m*n), SC O(n)
        vector<int> a = grid[0];
        vector<int> b= a;
        for(int i = 0; i < a.size(); i++){ 
            b[i] = !b[i];
        }
        if(grid.size() <= 1){
            return true;
        }else{
            for(auto &it : grid){
                if(it != a and it != b){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        //TC O(m*n), SC O(1)
        //core idea is, if grid[i][0] == 1 && grid[0][k] == 1 && grid[i][j] == 1 return false;
        int m = grid.size(), n = grid[0].size();

        for(int j = 0; j < n; j++){//check the first row
            if(grid[0][j]){
                for(int i = 0; i < m; i++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        for(int i = 1; i < m; i++){//check the first col
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