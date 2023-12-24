/*
Your car starts at position 0 and speed +1 on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions 'A' (accelerate) and 'R' (reverse):

When you get an instruction 'A', your car does the following:
position += speed
speed *= 2
When you get an instruction 'R', your car does the following:
If your speed is positive then speed = -1
otherwise speed = 1
Your position stays the same.
For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 --> 3, and your speed goes to 1 --> 2 --> 4 --> -1.

Given a target position target, return the length of the shortest sequence of instructions to get there.

 

Example 1:

Input: target = 3
Output: 2
Explanation: 
The shortest instruction sequence is "AA".
Your position goes from 0 --> 1 --> 3.
Example 2:

Input: target = 6
Output: 5
Explanation: 
The shortest instruction sequence is "AAARA".
Your position goes from 0 --> 1 --> 3 --> 7 --> 7 --> 6.
 

Constraints:

1 <= target <= 104
*/

#include <cmath>//for floor()
#include <math.h> //for log2()
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int racecar(int target) {
        //credit to rowe1227, BFS
        // 1. Initialize double ended queue as 0 moves, 0 position, +1 velocity
        queue<vector<int>> q;
        q.push({0, 0, 1});
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
            q.push({moves + 1, pos + vel, 2 * vel});
            
            // 3. Only consider changing the direction of the car if one of the following conditions is true
            //    i.  The car is driving away from the target.
            //    ii. The car will pass the target in the next move.  
            if ((pos + vel > target && vel > 0) || (pos + vel < target && vel < 0)) {
                q.push({moves + 1, pos, (vel > 0) ? -1 : 1});
            }
        }
        
        return 0;
    }
};


class Solution {
public:
    int racecar(int target) {
        //credit to lee215 and explanation from LuckyPㄒㄒnts. TC O(target*logtarget), SC O(target)
        if(memo[target] > 0){
            return memo[target];
        }
        int n = floor(log2(target)) + 1, res;// Smallest power of 2 greater than target
        if(1 << n == target + 1){// Case when target is exactly 2^n - 1
            memo[target] = n;
        }else{
            memo[target] = racecar((1 << n) - 1 - target) + n + 1;
            for (int m = 0; m < n - 1; ++m){
                memo[target] = min(memo[target], racecar(target - (1 << (n - 1)) + (1 << m)) + n + m + 1);
            }
                
        }
        return memo[target];
    }
private:
    int memo[10001];
};