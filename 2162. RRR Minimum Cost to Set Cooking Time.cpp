#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        mCost = moveCost;
        pCost = pushCost;
        return min(calTimeCost(startAt, targetSeconds/60, targetSeconds%60), calTimeCost(startAt, targetSeconds/60 - 1, targetSeconds%60 + 60));
    }
private:
    int mCost;
    int pCost;
    int calTimeCost(int startAt, int minute, int second){
        if(min(minute, second) < 0 || max(minute, second) > 99){
            return INT_MAX;
        }

        string timeStr = to_string(minute*100 + second);
        int ans = 0, i = 0;
        while(i < timeStr.size()){
            ans += pCost;
            if(startAt != timeStr[i] - '0'){
                ans += mCost;
                startAt = timeStr[i] - '0';
            }
            i++;
        }
        return ans;
    }
};