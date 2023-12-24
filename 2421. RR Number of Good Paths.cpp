#include <vector>
#include <map>
#include <unordered_map>
#include <numeric>
using namespace std;

class UnionFind {
    //credit to kiranpalsingh1806 and Editorial
    /*
    Time complexity: O(n⋅log(n))
    Space complexity: O(n)
    */
private:
    vector<int> parent, rank;
    int counter;
public:
    UnionFind(int cnt){
        counter = cnt;
        parent = vector<int>(cnt);
        rank = vector<int>(cnt, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int p){
        if(parent[p] == p){
            return p;
        }
        return parent[p] = find(parent[p]);
    }

    bool isConnected(int p, int q){
        return find(p) == find(q);
    }

    void connect(int p, int q){
        int pParent = find(p), qParent = find(q);
        if(pParent == qParent){
            return;
        }
        if(rank[pParent] < rank[qParent]){
            parent[pParent] = qParent;
        }else{
            parent[qParent] = pParent;
            if(rank[pParent] == rank[qParent]){
                rank[qParent]++;
            }
        }
        counter--;
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(), goodPathCounter = 0;
        vector<vector<int>> adjacentList(n);
        map<int, vector<int>> sameVal;//ordered

        for(int i = 0; i < n; i++){
            sameVal[vals[i]].push_back(i);
        }

        for(auto &edge:edges){
            int start = edge[0], end = edge[1];

            if(vals[start] > vals[end]){
                adjacentList[start].push_back(end);
            }else{
                adjacentList[end].push_back(start);
            }
        }

        UnionFind uf(n);

        for(auto &[value, nodeGroup]: sameVal){
            for(int &node:nodeGroup){
                for(int &adj:adjacentList[node]){
                    uf.connect(node, adj);
                }
            }

            unordered_map<int, int> componentCount;

            for(int &node:nodeGroup){
                componentCount[uf.find(node)]++;
            }

            goodPathCounter += nodeGroup.size();

            for(auto &[_, size]: componentCount){
                goodPathCounter += (size)*(size - 1)/2;
            }
        }

        return goodPathCounter;
    }
};