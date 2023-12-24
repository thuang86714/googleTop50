#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxi = 0, m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                maxi = max(maxi, findMax(matrix, i, j, -1));
            }
        }
        return maxi;
    }
private:
    int memo[200][200] = {};
    vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int findMax(vector<vector<int>>& matrix, int x, int y, int prev){
        if(x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size() || matrix[x][y] <= prev){
            return 0;
        }
        if(memo[x][y]){
            return memo[x][y];
        }
        int maxVal = 0;
        for(int k = 0; k < dirs.size(); k++){
            int newX = x + dirs[k].first;
            int newY = y + dirs[k].second;
            maxVal = max(maxVal, findMax(matrix, newX, newY, matrix[x][y]));
        }
        return memo[x][y] = maxVal + 1;
    }
};