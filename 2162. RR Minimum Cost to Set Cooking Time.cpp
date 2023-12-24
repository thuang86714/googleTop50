#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        mCost = moveCost;
        pCost = pushCost;
        int minute = targetSeconds/60;
        int second = targetSeconds%60;
        return min(calTimeCost(startAt, minute, second), calTimeCost(startAt, minute - 1, second + 60));
    }
private:
    int mCost;
    int pCost;
    int calTimeCost(int startAt, int minute, int second){
        //boundary check
        if(min(second, minute) < 0 || max(second, minute) > 99){
            return INT_MAX;
        }
        int costSum = 0;
        string timeStr = to_string(minute*100 + second);
        int i = 0;
        while(i < timeStr.size()){
            costSum += pCost;
            if(startAt != timeStr[i] - '0'){
                costSum += mCost;
                startAt = timeStr[i] - '0';
            }
            i++;
        }
        return costSum;
    }
};