#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;


class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sort(logs.begin(), logs.end());

        for(auto &log:logs){
            int x = find(log[1]);
            int y = find(log[2]);
            if(x != y){
                n--;
                if(n == 1){
                    return log[0];
                }
                parent[x] =y;
            }
        }
        return -1;
    }
private:
    vector<int> parent;
    int find(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }
};