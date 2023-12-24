#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
      //TC O(m*n), SC O(m + n)
        unordered_map<int, int> hori, vert, diag, aDiag;
        int ans = 0;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(!mat[i][j]){
                    hori[i] = vert[j] = diag[i - j] = aDiag[i + j] = 0;
                }else{
                    ans = max(ans, ++hori[i]);
                    ans = max(ans, ++vert[j]);
                    ans = max(ans, ++diag[i - j]);
                    ans = max(ans, ++aDiag[i + j]);
                }
            }
        }
        return ans;
    }
};