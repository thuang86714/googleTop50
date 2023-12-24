#include <vector>
using namespace std;
//credit to balajirai

class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        int len = variables.size();
        
        for(int i = 0; i < len; i++){
            int a = variables[i][0], b = variables[i][1], c = variables[i][2], m = variables[i][3];
            if(m <= target){
                continue;
            }
            int innerMost = power(a, b);
            int res = power2(innerMost, c, m);
            if(res == target){
                ans.push_back(i);
            }
        }
        return ans;
    }
private:
    int power(int a, int b) {
    int result = 1;
    while(b) {
        if (b & 1) 
        result = ((result%10) * (a%10))%10;
        a = (a%10) * (a%10);
        b >>= 1;
    }
    return result;
    }
    int power2(int a, int b, int mod) {
        int result = 1;
        while(b) {
            if (b & 1) 
            result = ((result%mod) * (a%mod))%mod;
            a = (a%mod) * (a%mod);
            b >>= 1;
        }
    return result;
    }
};