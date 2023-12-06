#include <queue>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <bitset>
using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        //credit to votrubac, DFS with bitset
        len = bombs.size();
        graph.resize(len);
        buildGraph(bombs);
        int res = 0;
        for(int i = 0; i < len && res < len; i++){
            res = max(res, calBomb(i, bitset<100>() = {}));
        }
        return res;
    }
private:
    vector<vector<int>> graph;
    int len;
    void buildGraph(vector<vector<int>>& bombs){
        for(int i = 0; i < len; i++){
            long long x = bombs[i][0], y = bombs[i][1], r2 = (long long)pow(bombs[i][2], 2);
            for(int j = 0; j < len; j++){
                if(pow((x - bombs[j][0]), 2) + pow((y - bombs[j][1]), 2) <= r2){
                    graph[i].push_back(j);
                }
            }
        }
    }

    int calBomb(int i, bitset<100> &detonated){
        if(!detonated[i]){
            detonated[i] = true;
            for(int nextBomb:graph[i]){
                calBomb(nextBomb, detonated);
            }
        }
        return detonated.count();
    }
};

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        //BFS, credit to votrubac, TLE
        len = bombs.size();
        int res = 0;
        graph.resize(len);
        buildGraph(bombs);
        for(int i = 0; i < len && res < len; i++){
            vector<int> toVisit{i};
            unordered_set<int> visited{i};
            while(!toVisit.empty()){
                vector<int> newToVisit;
                for(int bomb: toVisit){
                    for(int nextBomb: graph[bomb]){
                        if(!visited.count(nextBomb)){
                            newToVisit.push_back(nextBomb);
                            visited.insert(nextBomb);
                        }
                    }
                }
                swap(newToVisit, toVisit);
            }
            res = max(res, (int)visited.size());
        }
        return res;
    }
private:
    vector<vector<int>> graph;
    int len;
    void buildGraph(vector<vector<int>>& bombs){
        for(int i = 0; i < len; i++){
            long long x = bombs[i][0], y = bombs[i][1], r2 = (long long)pow(bombs[i][2], 2);
            for(int j = 0; j < len; j++){
                if(pow((x - bombs[j][0]), 2) + pow((y - bombs[j][1]), 2) <= r2){
                    graph[i].push_back(j);
                }
            }
        }
    }


};