#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        //credit to wh0ami
        /*
        Let NNN be the number of people and MMM be the number of logs.
        Time Complexity: O(N+MlogM+Mα(N))
        O(N+M)O(N + M)O(N+M) or O(N+log⁡M)O(N + \log M)O(N+logM)
        */
        sort(logs.begin(), logs.end());
        parent.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);

        for(auto &log:logs){
            int x = find(log[1]);
            int y = find(log[2]);

            if(x != y){
                n--;
                if(n == 1){
                    return log[0];
                }
                parent[y] = x;
            }
        }

        return -1;
    }
private:
    vector<int> parent;
    int find(int n){
        if(parent[n] == n){
            return n;
        }else{
            return parent[n] = find(parent[n]);
        }
    }
};