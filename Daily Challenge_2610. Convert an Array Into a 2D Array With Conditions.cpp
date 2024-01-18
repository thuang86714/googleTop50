#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        //TC O(n), SC O(n)
        unordered_map<int, int> intCounter;
        int maxCount = 0;
        for(int num:nums){
            intCounter[num]++;
            maxCount = max(maxCount, intCounter[num]);
        }
        vector<vector<int>> res(maxCount);
        for(auto &it:intCounter){
            int count = 0;
            while(it.second > count){
                res[count%maxCount].push_back(it.first);
                count++;
            }
        }

        return res;
    }
};