#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xCoordinates;
        for(auto &point:points){
            xCoordinates.push_back(point[0]);
        }
        sort(xCoordinates.begin(), xCoordinates.end());
        int ans = 0;
        for(int i = 1; i < xCoordinates.size(); i++){
            ans = max(ans, xCoordinates[i] - xCoordinates[i - 1]);
        }
        return ans;
    }
};