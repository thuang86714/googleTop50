

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //credit to archit91, TC O(m*n), SC O(m*n)
        maxPath = 0, n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
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
        if(i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] <= prev){
            return 0;
        }
        if(memo[i][j]){
            return memo[i][j];
        }

        int maxVal = 0;
        for(int k = 0; k < dirs.size(); k++){
            maxVal = max(maxVal, findMax(matrix, i + dirs[k].first, j + dirs[k].second, matrix[i][j]));
        }
        return memo[i][j] = 1 + maxVal;
    }
};

class Solution {
    //credit to archit91, TLE
public:
    int moves[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };   // all the moves available to us - top, down, left, right
int longestIncreasingPath(vector<vector<int>>& matrix) {
	int maxPath = 1; // atleast one cell can always be selected in the path
	// explore each cell of matrix to find longest path achievable from that cell and finally return the maximum
	for(int i = 0; i < matrix.size(); i++)
		for(int j = 0; j < matrix[0].size(); j++)
			maxPath = max(maxPath, solve(matrix, i, j));		        
	return maxPath;
}
// recursive solver for each cell 
int solve(vector<vector<int>>& mat, int i, int j){
	int MAX = 1;  // max length of path starting from cell i,j of matrix
	// choosing all the 4 moves available for current cell
	for(int k = 0; k < 4; k++){
		int new_i = i + moves[k][0], new_j = j + moves[k][1];
		// bound checking as well as move to next cell only when it is greater in value
		if(new_i < 0 || new_j < 0 || new_i >= mat.size() || new_j >= mat[0].size() || mat[new_i][new_j] <= mat[i][j]) continue;
		// MAX will be updated each time to store maximum of path length from each move
		MAX = max(MAX, 1 + solve(mat, new_i, new_j));
	}         
	return MAX;
}
};