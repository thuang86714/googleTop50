/*
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

 

Example 1:
Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.

Example 2:
Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 50
0 <= grid[i][j] < n2
Each value grid[i][j] is unique.
*/
#include <vector>
#include <queue>
using namespace std;
struct cell{
    int num, x, y;
    cell(int a, int b, int c): num(a), x(b), y(c){}
    bool operator< (const cell &d) const {return num > d.num;}
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        //credit to lee215
        int n = grid.size(), res = 0;
        priority_queue<cell> minHeap;
        minHeap.push(cell(grid[0][0], 0, 0));
        vector<vector<int>> visited(n, vector<int> (n, 0));
        visited[0][0] = 1;

        while(true){
            auto p = minHeap.top();
            minHeap.pop();
            res = max(res, p.num);
            if(p.x == n - 1 && p.y == n - 1){
                return res;
            }

            for(int i = 0; i < dirs.size(); i++){
                int newX = p.x + dirs[i].first;
                int newY = p.y + dirs[i].second;
                if(newX >= 0 && newX < n && newY >= 0 && newY < n && !visited[newX][newY]){
                    visited[newX][newY] = 1;
                    minHeap.push(cell(grid[newX][newY], newX, newY));
                }
            }
        }
    }
private:
    vector<pair<int, int>> dirs{{0,1}, {0, -1}, {1, 0}, {-1, 0}};
};