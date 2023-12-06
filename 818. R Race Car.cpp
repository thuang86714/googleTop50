#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int racecar(int target) {
        //credit to rowe1227 and jacklee20499, BFS
        /*
        Time complexity: O(2^n*logn)
        Space complexity: O(2^n)
        */
        // 1. Initialize double ended queue as 0 moves, 0 position, +1 velocity
        queue<vector<int>> q;
        q.push({0, 0, 1});
        set<pair<int, int>> memo;
        while (!q.empty()) {
            
            vector<int> item = q.front();
            q.pop();
            
            // (moves) moves, (pos) position, (vel) velocity)
            int moves = item[0];
            int pos = item[1];
            int vel = item[2];
            
            if (pos == target) return moves;
            
            // Avoid integer overflow - stop whenever we've passed twice the magnitude of target.
            if (abs(pos) > 2 * target) continue;
            
            // 2. Always consider moving the car in the direction it is already going
            if(!memo.count({pos + vel, 2 * vel})){
                q.push({moves + 1, pos + vel, 2 * vel});
                memo.insert({pos + vel, 2 * vel});
            }
            
            // 3. Only consider changing the direction of the car if one of the following conditions is true
            //    i.  The car is driving away from the target.
            //    ii. The car will pass the target in the next move.  
            if ((pos + vel > target && vel > 0) || (pos + vel < target && vel < 0)) {
                if(!memo.count({pos, (vel > 0) ? -1 : 1})){
                    q.push({moves + 1, pos, (vel > 0) ? -1 : 1});
                    memo.insert({pos, (vel > 0) ? -1 : 1});
                }
            }
        }
        
        return 0;
    }
};


class Solution {
public:
    int racecar(int target) {
        //credit to jacklee20499, Recursion + Space Optimized ver
        for(int i = 1; i <= target; i++){
            int n = floor(log2(i)) + 1;
            if((1 << n) == i + 1){
                memo[i] = n;
                continue;
            }

            memo[i] = memo[(1 << n) - 1 - i] + n + 1;

            for(int m = 0; m < n - 1; m++){
                memo[i] = min(memo[i], memo[i - (1 <<(n - 1)) + (1 << m)] + m + n + 1);
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
        //credit to lee215 and LuckyPants, TC O(tlogt), SC O(t + logt)
        if(memo[target] > 0){
            return memo[target];
        }
        int n = floor(log2(target)) + 1;
        int curSteps;
        if((1 << n) == target + 1){
            return memo[target] = n;
        }else{
            memo[target] = racecar((1 << n) - 1 - target) + n + 1;
            for(int m = 0; m < n - 1; m++){//worst case n - 1 ~= target
                memo[target] = min(memo[target], racecar(target - ((1 << (n - 1))) + (1 << m)) + m + n + 1);
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
        //credit to lee215, recursion without memo, TC O(t^2), TLE
        int n = floor(log2(target)) + 1;
        int curSteps;
        if((1 << n) == target + 1){
            return n;
        }else{
            curSteps = racecar((1 << n) - 1 - target) + n + 1;
            for(int m = 0; m < n - 1; m++){
                curSteps = min(curSteps, racecar(target - ((1 << (n - 1))) + (1 << m)) + m + n + 1);
            } 
        }
        return curSteps;
    }
};