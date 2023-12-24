#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> left(n), right(n), cur(n), prev(n);
        for(int j = 0; j < n; j++){
            prev[j] = points[0][j];
        }

        for(int i = 1; i < m; i++){
            left[0] = prev[0];
            right[n - 1] = prev[n - 1];
            for(int j = 1; j < n; j++){
                left[j] = max(prev[j], left[j - 1] - 1);
            }

            for(int j = n - 2; j >= 0; j--){
                right[j] = max(prev[j], right[j + 1] - 1);
            }

            for(int j = 0; j < n; j++){
                cur[j] = points[i][j] + max(left[j], right[j]);
            }

            prev = cur;
        }

        return *max_element(prev.begin(), prev.end());
    }
};