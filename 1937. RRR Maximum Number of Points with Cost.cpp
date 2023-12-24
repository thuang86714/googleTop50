#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        if(m == 1){
            return *max_element(points[0].begin(), points[0].end());
        }
        vector<long long> left(n), right(n), prev(n), cur(n);
        for(int j = 0; j < n; j++){
            prev[j] = points[0][j];
        }

        for(int i = 1; i < m; i++){
            left[0] = prev[0];
            right[n - 1] = prev[n - 1];
            for(int j = 1; j < n; j++){
                left[j] = max(left[j - 1] - 1, prev[j]);
            }

            for(int j = n - 2; j >= 0; j--){
                right[j] = max(right[j + 1] - 1, prev[j]);
            }

            for(int j = 0; j < n; j++){
                cur[j] = max(left[j], right[j]) + points[i][j];
            }
            prev = cur;
        }

        return *max_element(cur.begin(), cur.end());
    }
};