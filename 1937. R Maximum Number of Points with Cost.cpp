#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long>pre(n);
        for(int i = 0; i < n; i++){
            pre[i] = points[0][i];
        }

        for(int i = 1; i < m; i++){
            vector<long long> left(n, 0), right(n, 0), cur(n, 0);
            left[0] = pre[0];
            right[n - 1] = pre[n - 1];
            for(int j = 1; j < n; j++){
                left[j] = max(left[j - 1] - 1, pre[j]);
            }
            for(int j = n - 2; j >= 0; j--){
                right[j] = max(right[j + 1] - 1, pre[j]);
            }
            for(int j = 0; j < n; j++){
                cur[j] = points[i][j] + max(left[j], right[j]);
            }
            pre = cur;
        }

        return *max_element(pre.begin(), pre.end());
    }
};