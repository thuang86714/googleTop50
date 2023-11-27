/*
The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:
We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).
Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 109 + 7.

 

Example 1:

Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.
Example 2:

Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
Example 3:

Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.
 

Constraints:

1 <= n <= 5000
*/
#include <vector>
using namespace std;

class Solution {
public:
    //LeetCode official Solution, Top-Down, SC O(n), TC O(n)
    vector<vector<int>> memo;
    int n;
    int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    int dp(int remain, int square) {
        if (remain == 0) {
            return 1;
        }
        
        if (memo[remain][square] != 0) {
            return memo[remain][square];
        }
        
        int ans = 0;
        for (int nextSquare : jumps[square]) {
            ans = (ans + dp(remain - 1, nextSquare)) % MOD;
        }
        
        memo[remain][square] = ans;
        return ans;
    }
    
    int knightDialer(int n) {
        this->n = n;
        memo = vector(n + 1, vector(10, 0));
        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + dp(n - 1, square)) % MOD;
        }
        
        return ans;
    }
};

class Solution {
public:
    int knightDialer(int n) {
        //credit to NeetCode, TC O(n), SC O(1), Bottom-Up Dynamic Programming
        if(n == 1){
            return 10;
        }
        vector<int> memo(10, 1);
        vector<vector<int>> jumpTo = {
            {4, 6}, 
            {6, 8}, 
            {7, 9}, 
            {4, 8}, 
            {0, 3, 9}, 
            {}, 
            {0, 1, 7}, 
            {2, 6}, 
            {1, 3}, 
            {2, 4}
        };
        for(int i = 1; i < n; i++){
            vector<int> nextMemo(10, 0);
            for(int j = 0; j < 10; j++){
                for(int num:jumpTo[j]){
                    nextMemo[num] = (nextMemo[num] + memo[j])%mod; 
                }
            }
            memo = nextMemo;
        }

        int res = 0;
        for(int num:memo){
            res = (res + num)%mod;
        }
        return res;
    }
private:
    int mod = 1e9+7;
};