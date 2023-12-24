#include <vector>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        //DFS
        buildGraph(bombs);
        int ans = 0, len = bombs.size();
        for(int i = 0; i < len; i++){
            ans = max(ans, calBombDFS(i, bitset<100>() = {}));
        }
        return ans;
    }
private:
    unordered_map<int, vector<int>> graph;
    void buildGraph(vector<vector<int>>& bombs){
        int len = bombs.size();
        for(int i = 0; i < len; i++){
            long long xI = bombs[i][0], yI = bombs[i][1], rSqr = (long long)pow(bombs[i][2], 2);
            for(int j = 0; j < len; j++){
                long long xJ = bombs[j][0], yJ = bombs[j][1];
                if(pow(xI - xJ, 2) + pow(yI - yJ, 2) <= rSqr){
                    graph[i].push_back(j);
                }
            }
        }
    }
    int calBombDFS(int bomb, bitset<100> &visited){
        if(visited[bomb]){
            return 0;
        }
        visited[bomb] = true;

        for(int nextBomb:graph[bomb]){
            calBombDFS(nextBomb, visited);
        }
        return visited.count();
    }
};

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = 0;
        buildGraph(bombs);
        for(int i = 0; i < bombs.size(); i++){
            ans = max(ans, calBombBFS(i));
        }
        return ans;
    }
private:
    unordered_map<int, vector<int>>graph;
    void buildGraph(vector<vector<int>>& bombs){
        for(int i = 0; i < bombs.size(); i++){
            long long int iX = bombs[i][0], iY = bombs[i][1], rSqr = (long long)pow(bombs[i][2], 2);
            for(int j = 0; j < bombs.size(); j++){
                int xDiff = bombs[j][0] - iX, yDiff = bombs[j][1] - iY;
                if(pow(xDiff, 2) + pow(yDiff, 2) <= rSqr){
                    graph[i].push_back(j);
                }
            }
        }
    }
    int calBombBFS(int bomb){
        vector<int> toVisit{bomb};
        unordered_set<int> visited;
        while(!toVisit.empty()){
            vector<int> nextVisit;
            for(int bomb:toVisit){
                for(int nextBomb:graph[bomb]){
                    if(!visited.count(nextBomb)){
                        nextVisit.push_back(nextBomb);
                        visited.insert(nextBomb);
                    }
                }
            }
            swap(nextVisit, toVisit);
        }
        return (int)visited.size();
    }
};