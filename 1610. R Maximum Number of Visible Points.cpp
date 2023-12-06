#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define PI 3.14159265

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        //credit to shivankacct and rowe1227(side note), TC O(n^2), SC O(n)
        int i, j, n = points.size(), samePoint = 0;
        vector<double> knownAngles;
        for(auto &point:points){
            if(point == location){
                samePoint++;
            }else{
                int xDiff = point[0] - location[0];
                int yDiff = point[1] - location[1];
                double calAngle = getAngle(xDiff, yDiff);
                knownAngles.push_back(calAngle);
            }
        }

        vector<double> cyclicAngle;
        for(double knownAngle:knownAngles){
            cyclicAngle.push_back(knownAngle);
            cyclicAngle.push_back(knownAngle + 360);
        }
        sort(cyclicAngle.begin(), cyclicAngle.end());

        //using sliding window to find ans;
        int res = 0;
        for(int i = 0, j = 0; i < cyclicAngle.size(); i++){
            while(j < cyclicAngle.size() && (cyclicAngle[j] - cyclicAngle[i] <= angle)){
                j++;
            }
            res = max(res, j - i);
        }
        return samePoint + res;
    }
private:
    double getAngle(int xDiff, int yDiff){
        return atan2(yDiff, xDiff)*180/PI;
    }
};