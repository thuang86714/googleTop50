#include <cmath>//for floor()
#include <math.h> //for log2()
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int racecar(int target) {
        if(memo[target]){
            return memo[target];
        }
        int n = floor(log2(target)) + 1;
        if((1 << n) == target + 1){
            return n;
        }else{
            memo[target] = racecar((1 << n) - target - 1) + n + 1;
            for(int m = 0; m < n - 1; m ++){
                memo[target] = min(memo[target], racecar(target - (1 << (n - 1)) + (1 << m)) + m + n + 1);
            }
        }
        return memo[target];
    }
private:
    int memo[10001];
};