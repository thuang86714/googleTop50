#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        maxPath = 0, m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                maxPath = max(maxPath, findMax(matrix, i, j, -1));
            }
        }
        return maxPath;
    }
private:
    int memo[200][200]{};
    int maxPath, n, m;
    vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int findMax(vector<vector<int>>& matrix, int i, int j, int prev){
        if(i < 0 || j < 0 || i >= m || j >= n || matrix[i][j] <= prev){
            return 0;
        }
        if(memo[i][j]){
            return memo[i][j];
        }
        int maxVal = 0;
        for(int k = 0; k < dirs.size(); k++){
            maxVal = max(maxVal, findMax(matrix, i + dirs[k].first, j + dirs[k].second, matrix[i][j]));
        }

        return memo[i][j] = maxVal + 1;
    }
};