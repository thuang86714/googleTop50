#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        //credit to lzl124631x and UgoTan(for explanation)
        nums.resize(2 * numSlots); // append 0s to make sure the length of `A` is `2 * numSlots`
        int N = nums.size();
        int nSelected = 1 << N;
        vector<int> dp(nSelected);//Let dp[m] be the maximum score given a bitmask m representing the selected numbers.
        for (int mask = 1; mask < nSelected; mask++) {
            int selected = __builtin_popcount(mask), slot = (selected + 1) / 2; 
            for (int i = 0; i < N; ++i) {
                if (mask >> i & 1) { // we assign A[i] to `slot`-th slot
                    dp[mask] = max(dp[mask], dp[mask ^ (1 << i)] + (slot & nums[i]));
                }
            }
        }
        return dp.back();
    }
};

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