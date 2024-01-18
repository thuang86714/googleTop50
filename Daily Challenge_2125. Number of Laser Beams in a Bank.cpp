#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        //TC O(n*m), SC O(1)
        int ans = 0, preRowDevice = 0, curRowDevice = 0;
        for(string rows:bank){
            for(char num:rows){
                if(num == '1'){
                    curRowDevice++;
                }
            }
            ans += preRowDevice*curRowDevice;
            if(curRowDevice){
                preRowDevice = curRowDevice;
                curRowDevice = 0;
            }
        }
        return ans;
    }
};