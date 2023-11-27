/*
You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
Example 2:

Input: nums = [13,10,35,24,76]
Output: 4
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
*/
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int revNum = rev(nums[i]);
            map[nums[i] - revNum]++;
        }
        long long int ans = 0;
        for(auto &it:map){
            int n = it.second;
            ans += (n*0.5)*(n - 1);
        }
        return ans % 1000000007;
    }
private:
    int rev(int x){//TC O(log10(L))
        int ans=0;
        while(x!=0){
            int digit=x%10;
            if(ans<INT_MIN/10   || ans>INT_MAX/10){
            return 0;
            }
            ans=ans*10+digit;
            x=x/10;
        }
        return ans;
    }
};


class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        vector<vector<int>> combo(3, nums);
        unordered_map<int, vector<int>> map;
        for(int i = 0; i < nums.size(); i++){
            combo[1][i] = rev(nums[i]);
            combo[2][i] = combo[0][i] - combo[1][i];
            map[combo[2][i]].push_back(i);
        }
        long long int ans = 0;
        for(auto &it:map){
            int n = it.second.size();
            ans += (n*0.5)*(n - 1);
        }
        return ans % 1000000007;
    }
private:
    int rev(int n){//O(log10(L))
        string tempStr = to_string(n);
        reverse(tempStr.begin(), tempStr.end());
        return stoi(tempStr);
    }
};


class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        //TLE
        vector<vector<int>> combo(2, nums);
        for(int i = 0; i < nums.size(); i++){
            combo[1][i] = rev(nums[i]);
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(combo[0][i] + combo[1][j] == combo[1][i] + combo[0][j]){
                    ans++;
                }
            }
        }
        return ans % 1000000007;
    }
private:
    int rev(int n){
        string tempStr = to_string(n);
        reverse(tempStr.begin(), tempStr.end());
        return stoi(tempStr);
    }
};