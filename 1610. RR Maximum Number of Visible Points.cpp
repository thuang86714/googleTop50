#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define PI 3.14159265

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int i, j, n = points.size(), samePoint = 0;
        vector<double> cyclicAngle;
        for(auto &point:points){
            if(point == location){
                samePoint++;
            }else{
                int xDiff = point[0] - location[0];
                int yDiff = point[1] - location[1];
                double calAngle = getAngle(xDiff, yDiff);
                cyclicAngle.push_back(calAngle);
                cyclicAngle.push_back(calAngle + 360);
            }
        }

        sort(cyclicAngle.begin(), cyclicAngle.end());
        int res = 0;
        for(int i = 0, j = 0; i < cyclicAngle.size(); i++){
            while(j < cyclicAngle.size() && (cyclicAngle[j] - cyclicAngle[i] <= angle)){
                j++;
            }
            res = max(res, j - i);
        }
        return res + samePoint;
    }
private:
    double getAngle(int xDiff, int yDiff){
        return atan2(yDiff, xDiff)*180/PI;
    }
};