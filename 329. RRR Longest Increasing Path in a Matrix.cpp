#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0, m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, findPathDFS(matrix, i, j, -1));
            }
        }
        return ans;
    }
private:
    vector<pair<int, int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int memo[200][200] = {};
    int findPathDFS(vector<vector<int>>& matrix, int x, int y, int prev){
        if(x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size() || matrix[x][y] <= prev){
            return 0;
        }
        if(memo[x][y]){
            return memo[x][y];
        }
        int ans= 0;
        for(int i = 0; i < dirs.size(); i++){
            int newX = x + dirs[i].first, newY = y + dirs[i].second;
            ans = max(ans, findPathDFS(matrix, newX, newY, matrix[x][y]));
        }
        return memo[x][y] = ans + 1;;
    }
};