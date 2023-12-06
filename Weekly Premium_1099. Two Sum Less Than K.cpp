#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        //TC O(nlogn), SC O(1)
        sort(nums.begin(), nums.end());
        int ans = -1;
        for(int i = 0; i < nums.size(); i++){
            int target = k - nums[i];
            int l = i + 1, r = nums.size() - 1;
            while(l <= r){
                int mid = r + (l - r)/2;
                if(nums[mid] >= target){
                    r = mid - 1;
                }else{
                    ans = max(ans, nums[mid] + nums[i]);
                    l = mid + 1;
                }
            }
        }

        return ans;
    }
};