#include <algorithm>
#include <string>
using namespace std;


class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        //credit to votrubac
        mCost = moveCost;
        pCost = pushCost;
        int minute = targetSeconds/60, second = targetSeconds%60;
        return min(calCost(startAt, minute, second), calCost(startAt, minute - 1, second + 60));
    }
private:
    int mCost;
    int pCost;
    int calCost(int pos, int minute, int second){
        if(min(minute, second) < 0 || max(minute, second) > 99){
            return INT_MAX;
        }
        int res = 0;
        string timeStr = to_string(minute*100 + second);
        for(auto digit:timeStr){
            res += pCost;
            if(pos != digit - '0'){
                res += mCost;
            }
            pos = digit - '0';
        }
        return res;
    }
};