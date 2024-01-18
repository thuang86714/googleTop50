#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> numCount;
        for(int n:nums){
            numCount[n]++;
        }
        int ans = 0;
        for(auto &[_,count]:numCount){
            if(count == 1){
                return -1;
            }else{
                ans += count/3 + (count%3 > 0);
            }
        }
        return ans;
    }
};