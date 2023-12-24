#include <vector>
#include <queue>
using namespace std;

#include <vector>

class Solution {
    //dfs, TC O(n^2logn), SC O(n^2)
public:
    int swimInWater(std::vector<std::vector<int>>& heightGrid) {
        
        int size = heightGrid.size();
        int lowerBound = heightGrid[0][0], upperBound = size * size - 1;
        
        while (lowerBound < upperBound) {
            int mid = lowerBound + (upperBound - lowerBound) / 2;
            if (isPathValid(heightGrid, mid))
                upperBound = mid;
            else
                lowerBound = mid + 1;
        }
        
        return lowerBound;
    }

private:
    bool isPathValid(std::vector<std::vector<int>>& heightGrid, int waterHeight) {
        int size = heightGrid.size();
        std::vector<std::vector<int>> visited(size, std::vector<int>(size, 0));
        std::vector<int> direction({-1, 0, 1, 0, -1});
        return dfs(heightGrid, visited, direction, waterHeight, 0, 0, size);
    }

    bool dfs(std::vector<std::vector<int>>& heightGrid, std::vector<std::vector<int>>& visited, 
             std::vector<int>& direction, int waterHeight, int row, int col, int size) {
        visited[row][col] = 1;

        for (int i = 0; i < 4; ++i) {
            int newRow = row + direction[i];
            int newCol = col + direction[i + 1];

            if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size &&
                visited[newRow][newCol] == 0 && heightGrid[newRow][newCol] <= waterHeight) {
                if (newRow == size - 1 && newCol == size - 1) 
                    return true;
                if (dfs(heightGrid, visited, direction, waterHeight, newRow, newCol, size)) 
                    return true;
            }
        }
        
        return false;
    }
};


class Dsu {
  public:
  vector<int>rank;
  vector<int>parent;
   Dsu(int n){
   rank.resize(n , 0);
   parent.resize(n , 0);
   for(int i=0; i<n; i++){
    parent[i]=i;
   }
   }
  
  int find(int node){
  if(node==parent[node])
  return node;
  return parent[node] = find(parent[node]);
  }

  void unionbysize(int u , int v){
  int paru = find(u);
  int parv = find(v);
  if(rank[paru]>rank[parv]){
  parent[parv] = paru;
  }
  else if(rank[parv]>rank[paru]){
  parent[paru] = parv;
  }
  else{
  parent[paru] = parv;
  rank[parv]++;
  }
  } 
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
    //Union-Find
    int n = grid.size();
    Dsu ds(n*n);
    int start = grid[0][0], end = grid[n - 1][n - 1];

    int times[n * n];
    for(int i=0; i<n; i++){
     for (int j = 0; j < n; j++){
      times[grid[i][j]] = i*n+j;
    }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
     
    for(int t=0; t< n*n ; t++){
     int row = times[t]/n;
     int col = times[t]%n;
     for(int i=0; i<4; i++){
      int nrow = row + dx[i];
      int ncol = col + dy[i];
     if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&  grid[nrow][ncol] <= t) 
        ds.unionbysize(t, grid[nrow][ncol]);
     }
     if(ds.find(start)== ds.find(end))
     return t;
    }
    return (n*n)-1;
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
       //credit to lee215 TC O(n^2*logn), SC O(n^2)
        int n = grid.size(), res = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({grid[0][0], 0, 0});
        vector<vector<int>> visited(n, vector<int> (n, 0));
        visited[0][0] = 1;

        while(true){
            auto curVec = minHeap.top();
            minHeap.pop();
            res = max(res, curVec[0]);
            if(curVec[1] == n - 1 && curVec[2] == n - 1){
                return res;
            }

            for(int i = 0; i < dirs.size(); i++){
                int newX = curVec[1] + dirs[i].first;
                int newY = curVec[2] + dirs[i].second;
                if(newX >= 0 && newX < n && newY >= 0 && newY < n && !visited[newX][newY]){
                    visited[newX][newY] = 1;
                    minHeap.push({grid[newX][newY], newX, newY});
                }
            }
        }
    }
private:
    vector<pair<int, int>> dirs{{0,1}, {0, -1}, {1, 0}, {-1, 0}};
};