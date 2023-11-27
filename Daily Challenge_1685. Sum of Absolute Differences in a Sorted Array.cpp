/*
You are given an integer array nums sorted in non-decreasing order.

Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).

 

Example 1:
Input: nums = [2,3,5]
Output: [4,3,5]
Explanation: Assuming the arrays are 0-indexed, then
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.

Example 2:
Input: nums = [1,4,6,8,10]
Output: [24,15,13,15,21]
 

Constraints:

2 <= nums.length <= 105
1 <= nums[i] <= nums[i + 1] <= 104

*/
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int leftsum = 0, n = nums.size(),rightsum =0;
        for(int i=0;i<n;i++) 
            rightsum+=nums[i];
        for (int i = 0; i < n; i++) {
            rightsum -= nums[i];
            leftsum += nums[i];
            nums[i] = rightsum - nums[i] * (n - i - 1) - leftsum + nums[i] * (i + 1);
        }
        return nums;
    }
};

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int rightSum = accumulate(nums.begin() + 1, nums.end(), 0);
        int leftSum = 0, n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++){
            int cur = rightSum - leftSum - nums[i]*(n - 2*i - 1);
            res.push_back(cur);
            if(i != n - 1){
                rightSum -= nums[i + 1];
            }
            leftSum += nums[i];
        }
        return res;
    }
};


class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        //MLE
        vector<int> res;
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                memo[i][j] = abs(nums[i] - nums[j]);
            }
        }

        for(int i = 0; i < n; i++){
            res.push_back(accumulate(memo[i].begin(), memo[i].end(), 0));
        }

        return res;
    }
};