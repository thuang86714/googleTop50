/*
You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.

 

Example 1:
Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.

Example 2:
Input: matrix = [[1,0,1,0,1]]
Output: 3
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.

Example 3:
Input: matrix = [[1,1,0],[1,0,1]]
Output: 2
Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m * n <= 105
matrix[i][j] is either 0 or 1.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        //credit to Invulnerable, similar to Aincrad-Lyu, TC O(m*(nlogn)), SC O(1)
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[j][i]){
                    matrix[j][i] += matrix[j - 1][i];
                }else{
                    matrix[j][i] = 0;
                }
            }
        }

        for(int i = 0; i < m; i++){
            sort(matrix[i].begin(), matrix[i].end());
            for(int j = 0; j < n; j++){
                ans = max(ans, matrix[i][j]*(n - j));
            }
        }

        return ans;
    }
};

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        //credit to Aincrad-Lyu, TC O(m*(nlogn)), SC O(n)
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<int> height(n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    height[j] = 0;
                }else{
                    height[j] += 1;
                }
            }

            vector<int> sortedHeight = height;
            sort(sortedHeight.begin(), sortedHeight.end());

            for(int j = 0; j < n; j++){
                ans = max(ans, sortedHeight[j]*(n - j));
            }
        }

        return ans;
    }
};