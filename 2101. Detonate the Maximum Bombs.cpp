/*
You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.

 

Example 1:
Input: bombs = [[2,1,3],[6,1,4]]
Output: 2
Explanation:
The above figure shows the positions and ranges of the 2 bombs.
If we detonate the left bomb, the right bomb will not be affected.
But if we detonate the right bomb, both bombs will be detonated.
So the maximum bombs that can be detonated is max(1, 2) = 2.

Example 2:
Input: bombs = [[1,1,5],[10,10,5]]
Output: 1
Explanation:
Detonating either bomb will not detonate the other bomb, so the maximum number of bombs that can be detonated is 1.

Example 3:
Input: bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
Output: 5
Explanation:
The best bomb to detonate is bomb 0 because:
- Bomb 0 detonates bombs 1 and 2. The red circle denotes the range of bomb 0.
- Bomb 2 detonates bomb 3. The blue circle denotes the range of bomb 2.
- Bomb 3 detonates bomb 4. The green circle denotes the range of bomb 3.
Thus all 5 bombs are detonated.
 

Constraints:

1 <= bombs.length <= 100
bombs[i].length == 3
1 <= xi, yi, ri <= 105
*/
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
            //given constraint 1 <= bombs.length <= 100
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
        //BFS, credit to votrubac
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