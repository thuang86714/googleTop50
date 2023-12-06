#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        //greedy
        int ans = 0;
        for(int i = 0; i < points.size() - 1; i++){
            int curX = points[i][0], nextX = points[i + 1][0];
            int curY = points[i][1], nextY = points[i + 1][1];
            int move = max(abs(curX - nextX), abs(curY - nextY));
            ans += move;
        }
        return ans;
    }
};