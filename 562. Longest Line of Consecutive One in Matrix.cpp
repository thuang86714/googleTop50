/*
Given an m x n binary matrix mat, return the length of the longest line of consecutive one in the matrix.

The line could be horizontal, vertical, diagonal, or anti-diagonal.

 

Example 1:
Input: mat = [[0,1,1,0],[0,1,1,0],[0,0,0,1]]
Output: 3

Example 2:
Input: mat = [[1,1,1,1],[0,1,1,0],[0,0,0,1]]
Output: 4
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
*/
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        //credit to zzg_zzm in StefanPochmann's post, TC O(m*n), SC O(m*n)
        unordered_map<int, int> horiLen, verLen, diaLen, adiaLen;

        int ans = 0;

        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(!mat[i][j]){
                    horiLen[i] = verLen[j] = diaLen[i - j] = adiaLen[i + j] = 0;
                }else{
                    ans = max(ans, ++horiLen[i]);
                    ans = max(ans, ++verLen[j]);
                    ans = max(ans, ++diaLen[i - j]);
                    ans = max(ans, ++adiaLen[i + j]);
                }
            }
        }
        return ans;
    }
};