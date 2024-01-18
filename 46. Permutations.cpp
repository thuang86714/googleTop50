#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //TC O(n*n!), SC O(n)
        findPermutation(nums, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    void findPermutation(vector<int> &nums, int idx){
        if(idx == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            findPermutation(nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }
};