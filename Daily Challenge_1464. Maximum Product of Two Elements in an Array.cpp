#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int num1 = 0, num2 = 0;
        for(int &num:nums){
            if(num > num1){
                num2 = exchange(num1, num);
            }else{
                num2 = max(num2, num);
            }
        }
        return (num1 - 1)*(num2 - 1);
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return (nums[n - 1] - 1)*(nums[n - 2] - 1);
    }
};