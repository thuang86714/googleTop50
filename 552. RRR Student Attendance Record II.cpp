#include <vector>
using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        //TC O(n), SC O(1)
        vector<vector<int>> prev(2, vector<int> (3, 1)), cur(2, vector<int> (3, 0));

        for(int i = 1; i <= n; i++){
            for(int absent = 0; absent < 2; absent++){
                for(int late = 0; late < 3; late++){
                    int A, L, P;
                    A = L = P = 0;

                    if(absent > 0){
                        A = prev[absent - 1][2];
                    }
                    if(late > 0){
                        L = prev[absent][late - 1];
                    }

                    P = prev[absent][2];
                    cur[absent][late] = ((A + L)%MOD + P)%MOD;
                }
            }
            prev = cur;
        }
        return cur[1][2];
    }
private:
    int MOD = 1e9+7;
};