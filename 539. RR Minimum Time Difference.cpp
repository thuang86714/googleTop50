#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        for(string &time:timePoints){
            convertToMin(time);
        }
        sort(minute.begin(), minute.end());
        int ans = 1441, n = minute.size();
        for(int i = 0; i < n; i++){
            if(i == n - 1){
                ans = min(ans, 1440 - abs(minute[(i + 1)%n] - minute[i%n]));
                continue;
            }
            ans = min(ans, minute[(i + 1)%n] - minute[i%n]);
        }
        return ans;
    }
private:
    vector<int> minute;
    void convertToMin(string &time){
        int hr = stoi(time.substr(0, 2));
        int mins = stoi(time.substr(3));
        minute.push_back(hr*60 + mins);
    }
};