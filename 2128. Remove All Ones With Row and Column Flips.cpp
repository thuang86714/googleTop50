/*
You are given an m x n binary matrix grid.

In one operation, you can choose any row or column and flip each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Return true if it is possible to remove all 1's from grid using any number of operations or false otherwise.

 

Example 1:
Input: grid = [[0,1,0],[1,0,1],[0,1,0]]
Output: true
Explanation: One possible way to remove all 1's from grid is to:
- Flip the middle row
- Flip the middle column

Example 2:
Input: grid = [[1,1,0],[0,0,0],[0,0,0]]
Output: false
Explanation: It is impossible to remove all 1's from grid.

Example 3:
Input: grid = [[0]]
Output: true
Explanation: There are no 1's in grid.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is either 0 or 1.
*/
#include <vector>
using namespace std;

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        //credit to eminem18753, TC O(m*n), SC O(1)
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