#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        unordered_map<int, int> hori, verti, diag, aDiag;
        int ans = 0;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(!mat[i][j]){
                    hori[i] = verti[j] = diag[i - j] = aDiag[i + j] = 0;
                }else{
                    ans = max(ans, ++hori[i]);
                    ans = max(ans, ++verti[j]);
                    ans = max(ans, ++diag[i - j]);
                    ans = max(ans, ++aDiag[i + j]);
                }
            }
        }
        return ans;
    }
};