#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <bitset>
using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        buildGraph(bombs);
        int ans = 0;
        for(int i = 0; i < bombs.size(); i++){
            ans = max(ans, calBomb(i, bitset<100>() = {}));
        } 
        return ans;
    }
private:
    unordered_map<int, vector<int>> graph;
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
    int calBomb(int i, bitset<100> &detonated){
        if(!detonated[i]){
            detonated[i] = true;
            for(int &nextBomb:graph[i]){
                calBomb(nextBomb, detonated);
            }
        }
        return detonated.count();
    }
};


class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = 0;
        buildGraph(bombs);
        for(int i = 0; i < bombs.size(); i++){
            vector<int> toVisit{i};
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
            ans = max(ans, (int)visited.size());
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
};