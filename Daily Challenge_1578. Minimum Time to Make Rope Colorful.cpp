#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        //TC O(n), SC O(1)
        int ans = 0, i = 0, j = 0;
        while(i < colors.size() && j < colors.size()){
            while(i < colors.size() && colors[i] == colors[j]){
                i++;
            }
            if(i - j > 1){
                int curMax = neededTime[j];
                for(int k = j; k < i; k++){
                    curMax = max(curMax, neededTime[k]);
                    ans += neededTime[k];
                }
                ans -= curMax;
            }
            j = i;
            i++;
        }
        return ans;
    }
};