/*
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 

Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.
*/
#include <vector>
#include <bitset>
#include <string>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        //credit to ashucrma, TC O(n), SC O(1)
        string ans = "";
        for(int i = 0; i < nums.size(); i++){
            ans += nums[i][i] == '0'? '1':'0'; 
        }
        return ans;
    }
};

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        //parital credit to votrubac
        unordered_set<string> dict{nums.begin(), nums.end()};
        int i = 0, len = nums.size(), end = pow(2, len);
        while(i < end){
            string binStr = std::bitset<16>(i).to_string().substr(16 - len);
            if(!dict.count(binStr)){
                return binStr;
            }
            i++;
        }
        return "";
    }
};