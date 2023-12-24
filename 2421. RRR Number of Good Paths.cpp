#include <vector>
#include <map>
using namespace std;

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
        int counter = 0;
        map<int, vector<int>> sameVal;
        for(int i = 0; i < vals.size(); i++){
            sameVal[vals[i]].push_back(i);
        }

        //build graph
        unordered_map<int, vector<int>> adj;
        for(auto &e:edges){
            int start = e[0], end = e[1];
            if(vals[start] > vals[end]){
                adj[start].push_back(end);
            }else{
                adj[end].push_back(start);
            }
        }

        UnionFind uf(vals.size());

        for(auto &[val, nodeGroup]:sameVal){
            for(auto &node:nodeGroup){
                for(int &nei:adj[node]){
                    uf.connect(node, nei);
                }
            }

            unordered_map<int, int> componentCount;

            for(int &node:nodeGroup){
                componentCount[uf.find(node)]++;
            }

            counter += nodeGroup.size();

            for(auto &[_,size]:componentCount){
                counter += size*(size - 1)/2;
            }
        }
        return counter;
    }
};


class Solution {
public:
    //credit to jacklee20499
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        ans = 0;
        auto graph = buildGraph(edges);
        
        dfs(graph, vals, 0, -1);
        return ans+vals.size();
    }
private:
    int ans;
    
    vector<vector<int>> buildGraph(vector<vector<int>>& edges){
        vector<vector<int>> graph(edges.size()+1);
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        return graph;
    }
    
    map<int, int> dfs(vector<vector<int>>& graph, vector<int> & vals, int cur, int parent){
        map<int, int> count;
        count[vals[cur]]++;
        
        for(auto& nxt: graph[cur]){
            if(nxt == parent) continue;
            
            map<int, int> subTree = dfs(graph, vals, nxt, cur);
            
            auto it = subTree.lower_bound(vals[cur]);
            subTree.erase(subTree.begin(), it);
            
            if(subTree.size() > count.size()){
                swap(subTree, count);
            }
            
            for(auto &[key, freq]: subTree){
               ans += freq * count[key];        
            }
        
            for(auto &[key, freq]: subTree){
                count[key] += freq;
            }
        }
        
        return count;
    }
};