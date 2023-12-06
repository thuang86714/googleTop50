#include <vector>
using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        //credit to KJer and VAIBHAV_SHORAN
        //TC O(n), SC O(1)
        vector<vector<int>> prev(2, vector<int> (3, 1)), cur(2, vector<int> (3, 0));

        for(int i = 1; i <= n; i++){
            for(int absent = 0; absent <= 1; absent++){
                for(int late = 0; late <= 2; late++){
                    int A, L, P;
                    A = L = P = 0;

                    if(absent > 0){
                        A = prev[absent - 1][2];
                    }

                    if(late > 0){
                        L = prev[absent][late - 1];
                    }

                    P = prev[absent][2];

                    cur[absent][late] = ((A + L)%mod + P) % mod;
                }
            }
            prev = cur;
        }
        return cur[1][2];
    }
private:
    int mod = 1e9 + 7;
};