/*
You are given an integer array nums of length n and an integer numSlots such that 2 * numSlots >= n. There are numSlots slots numbered from 1 to numSlots.

You have to place all n integers into the slots such that each slot contains at most two numbers. The AND sum of a given placement is the sum of the bitwise AND of every number with its respective slot number.

For example, the AND sum of placing the numbers [1, 3] into slot 1 and [4, 6] into slot 2 is equal to (1 AND 1) + (3 AND 1) + (4 AND 2) + (6 AND 2) = 1 + 1 + 0 + 2 = 4.
Return the maximum possible AND sum of nums given numSlots slots.

 

Example 1:

Input: nums = [1,2,3,4,5,6], numSlots = 3
Output: 9
Explanation: One possible placement is [1, 4] into slot 1, [2, 6] into slot 2, and [3, 5] into slot 3. 
This gives the maximum AND sum of (1 AND 1) + (4 AND 1) + (2 AND 2) + (6 AND 2) + (3 AND 3) + (5 AND 3) = 1 + 0 + 2 + 2 + 3 + 1 = 9.
Example 2:

Input: nums = [1,3,10,4,7,1], numSlots = 9
Output: 24
Explanation: One possible placement is [1, 1] into slot 1, [3] into slot 3, [4] into slot 4, [7] into slot 7, and [10] into slot 9.
This gives the maximum AND sum of (1 AND 1) + (1 AND 1) + (3 AND 3) + (4 AND 4) + (7 AND 7) + (10 AND 9) = 1 + 1 + 3 + 4 + 7 + 8 = 24.
Note that slots 2, 5, 6, and 8 are empty which is permitted.
 

Constraints:

n == nums.length
1 <= numSlots <= 9
1 <= n <= 2 * numSlots
1 <= nums[i] <= 15

*/
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


// OJ: https://leetcode.com/contest/weekly-contest-280/problems/maximum-and-sum-of-array/
// Author: github.com/lzl124631x
// Time: O(2^(2*numSlots) * numSlots)
// Space: O(2^(2*numSlots))
class Solution {
public:
    int maximumANDSum(vector<int>& A, int numSlots) {
        A.resize(2 * numSlots); // append 0s to make sure the length of `A` is `2 * numSlots`
        int N = A.size();
        vector<int> dp(1 << N);
        for (int m = 1; m < 1 << N; ++m) {
            int cnt = __builtin_popcount(m), slot = (cnt + 1) / 2; 
            for (int i = 0; i < N; ++i) {
                if (m >> i & 1) { // we assign A[i] to `slot`-th slot
                    dp[m] = max(dp[m], dp[m ^ (1 << i)] + (slot & A[i]));
                }
            }
        }
        return dp[(1 << N) - 1];
    }
};

class Solution{
public:
    int maximumANDSum(vector<int>& A, int ns) {
        int mask = pow(3, ns) - 1;
        vector<int> memo(mask + 1, 0);

        function<int(int, int)> dp =
        [&](int i, int mask) {
            int& res = memo[mask];
            if (res > 0) return res;
            if (i < 0) return 0;
            for (int slot = 1, bit = 1; slot <= ns; ++slot, bit *= 3)
                if (mask / bit % 3 > 0)
                    res = max(res, (A[i] & slot) + dp(i - 1, mask - bit));
            return res;
        };

        return dp(A.size() - 1, mask);
    }
};


class Solution {
public:
    int maximumANDSum(vector<int>& A, int ns) {
        //credit to lee215
        /*
        Time O(ns * 3^ns)
        Space O(3^ns)
        */
        int mask = pow(3, ns) - 1;
        vector<int> memo(mask + 1, 0);
        return dp(A.size() - 1, mask, ns, memo, A);
    }
    
    int dp(int i, int mask, int ns, vector<int>& memo, vector<int>& A) {
        if (memo[mask] > 0) return memo[mask];
        if (i < 0) return 0;
        for (int slot = 1, bit = 1; slot <= ns; ++slot, bit*= 3)
            if (mask / bit % 3 > 0)
                memo[mask] = max(memo[mask], (A[i] & slot) + dp(i - 1, mask - bit, ns, memo, A));
        return memo[mask];
    }
};