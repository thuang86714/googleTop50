#include <vector>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        buildGraph(bombs);
        int ans = 0;
        for(int i = 0; i < bombs.size(); i++){
            ans = max(ans, calBombs(i, bitset<100>() = {}));
        }
        return ans;
    }
private:
    unordered_map<int, vector<int>> graph;
    void buildGraph(vector<vector<int>>& bombs){
        for(int i = 0; i < bombs.size(); i++){
            long long x = bombs[i][0], y = bombs[i][1], rSqr = (long long)pow(bombs[i][2], 2);
            for(int j = 0; j < bombs.size(); j++){
                int nextX = bombs[j][0], nextY = bombs[j][1];
                if(pow(nextX - x, 2) + pow(nextY - y, 2) <= rSqr){
                    graph[i].push_back(j);
                }
            }
        }
    }

    int calBombs(int curBombs, bitset<100> &visited){
        if(visited[curBombs]){
            return 0;
        }
        visited[curBombs] = true;

        for(int nextBomb:graph[curBombs]){
            calBombs(nextBomb, visited);
        }

        return visited.count();
    }

};