#include <cmath>//for floor()
#include <math.h> //for log2()
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> nextStep;
        nextStep.push({0, 0, 1});
        while(!nextStep.empty()){
            auto curVec = nextStep.front();
            nextStep.pop();

            int move = curVec[0];
            int pos = curVec[1];
            int vel = curVec[2];

            if(pos == target){
                return move;
            }

            if(abs(pos) > 2*target){
                continue;
            }

            nextStep.push({move + 1, pos + vel, vel*2});

            if((pos + vel > target && vel > 0) || (pos + vel < target && vel < 0)){
                nextStep.push({move + 1, pos, (vel > 0)? -1: 1});
            }
        }
        return -1;
    }
};


class Solution {
public:
    int racecar(int target) {
        if(memo[target]){
            return memo[target];
        }

        int n = floor(log2(target)) + 1;
        if((1 << n) == target + 1){
            return memo[target] = n;
        }else{
            memo[target] = racecar((1 << n)- target - 1) + n + 1;
            for(int m = 0; m < n - 1; m++){
                memo[target] = min(memo[target], racecar(target - (1 << (n - 1)) + (1 << m)) + m + n + 1);
            }
        }
        return memo[target];
    }
private:
    int memo[10001];
};


class Solution {
public:
    int racecar(int target) {
        //credit to lee215, luckyPants, TC O(tlogt), SC O(t + logt)
        if(memo[target] > 0){
            return memo[target];
        }
        int n = floor(log2(target)) + 1;
        int cutSteps;
        if((1 << n) == target + 1){
            return memo[target] = n;
        }else{
            /*
            Use n A to arrive at 2^n-1 first, then use R to change the direction, by here there are n+1 operations (n A and one R), then the remaining is same as dp[2^n-1-i]
            */
            memo[target] = racecar((1 << n) - 1 - target) + n + 1;

            /*
            Use n-1 A to arrive at 2^(n-1)-1 first, then R to change the direction, use m A to go backward, then use R to change the direction again to move forward, by here there are n-1+2+m=n+m+1 operations (n-1 A, two R, m A) , current position is 2^(n-1)-1-(2^m-1)=2^(n-1)-2^m, the remaining operations is same as dp[i-(2^(n-1)-1)+(2^m-1)]=dp[i-2^(n-1)+2^m)].
            */
            for(int m = 0; m < n - 1; m++){
                memo[target] = min(memo[target], racecar(target - (1 << (n - 1)) + (1 << m)) + m + n + 1);
            }
        }
        return memo[target];
    }
private:
    int memo[10001];
};