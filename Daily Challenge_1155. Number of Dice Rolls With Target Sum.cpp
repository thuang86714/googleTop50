class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if(n == 0 || target <= 0){
            return n == target;
        }
        if(memo[n][target]){
            return memo[n][target] - 1;//since all memo cell are initially 0, +1 to distinguish from unvisited
        }
        int res = 0;
        for(int i = 1; i <= k; i++){
            res = (res + numRollsToTarget(n - 1, k, target - i))%MOD;
        }
        memo[n][target] = res + 1;
        return res;
    }
private:
    int memo[31][1001] = {};
    int MOD = 1e9+7;
};