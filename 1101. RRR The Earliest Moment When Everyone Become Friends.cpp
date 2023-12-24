#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        parent.resize(n);
        rank.resize(n);
        len = n;
        iota(parent.begin(), parent.end(), 0);
        sort(logs.begin(), logs.end());
        for(auto &log:logs){
            int x = log[1], y = log[2];
            connect(x, y);
            if(len == 1){
                return log[0];
            }
        }
        return -1;
    }
private:
    vector<int> parent;
    vector<int> rank;
    int len;
    void connect(int i, int j){
        int iParent = find(i), jParent = find(j);
        if(iParent == jParent){
            return;
        }else{
            if(rank[iParent] > rank[jParent]){
                parent[jParent] = iParent;
            }else{
                parent[iParent] = jParent;
                if(rank[iParent] == rank[jParent]){
                    rank[jParent]++;
                }
            }
            len--;
        }
    }
    int find(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }
};