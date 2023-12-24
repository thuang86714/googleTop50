#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowSum(m), colSum(n);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    rowSum[i]++;
                    colSum[j]++;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int cell = 2*rowSum[i] + 2*colSum[j] - m - n;
                grid[i][j] = cell;
            }
        }

        return grid;
    }
};


class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> diff;
        vector<int> rowSum(m), colSum(n);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    rowSum[i]++;
                    colSum[j]++;
                }
            }
        }

        for(int i = 0; i < m; i++){
            diff.push_back({});
            for(int j = 0; j < n; j++){
                int cell = 2*rowSum[i] + 2*colSum[j] - m - n;
                diff.back().push_back(cell);
            }
        }

        return diff;
    }
};