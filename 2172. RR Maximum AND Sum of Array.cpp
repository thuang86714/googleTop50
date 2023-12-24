#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int mask = pow(3, numSlots) - 1;
        vector<int> memo(mask + 1, 0);
        return findMax(nums.size() -1, mask, nums, numSlots, memo);
    }
private:
    int findMax(int curIdx, int mask, vector<int>& nums, int numSlots, vector<int> &memo){
        if(memo[mask] > 0){
            return memo[mask];
        }
        if(curIdx < 0){
            return 0;
        }
        for(int slot = 1, bit = 1; slot <= numSlots; slot++, bit *= 3){
            if(mask / bit % 3 > 0){//there's vacancy in this slot
                memo[mask] = max(memo[mask], (nums[curIdx]&slot) + findMax(curIdx - 1, mask - bit, nums, numSlots, memo));
            }
        }
        return memo[mask];
    }
};