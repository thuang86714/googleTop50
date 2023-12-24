#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> ans(m, vector<int> (n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int counter = 0, sum = 0;
                for(int I = max(0, i - 1); I < min(m, i + 2); I++){
                    for(int J = max(0, j - 1); J < min(n, j + 2); J++){
                        counter++;
                        sum += img[I][J];
                    }
                }
                ans[i][j] = floor(sum/counter);
            }
        }
        return ans;
    }
};