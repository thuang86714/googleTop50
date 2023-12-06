#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int minDiff = 1441, n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());

        for(int i = 0; i < n; i++){
            int diff = abs(calDiff(timePoints[i%n], timePoints[(i + 1)%n]));
            diff = min(diff, 1440 - diff);
            minDiff = min(minDiff, diff);
        }
        return minDiff;
    }
private:
    int calDiff(string time1, string time2){
        int hr1 = stoi(time1.substr(0, 2));
        int hr2 = stoi(time2.substr(0, 2));
        int min1 = stoi(time1.substr(3));
        int min2 = stoi(time2.substr(3));

        return (hr2 - hr1)*60 + (min2 - min1);
    }
};