#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        for(string timeStr:timePoints){
            time.push_back(calTime(timeStr));
        }

        sort(time.begin(), time.end());
        int ans = INT_MAX, n = time.size();
        for(int i = 0; i < n; i++){
            int diff = time[(i + 1)%n] - time[i%n];
            if(i == n - 1){
                diff = 1440 + diff;
            }
            ans = min(ans, diff); 
        }
        return ans;
    }
private:
    int calTime(string timeStr){
        int hour = stoi(timeStr.substr(0, 2));
        int minute = stoi(timeStr.substr(3));
        return hour*60 + minute;
    }
};