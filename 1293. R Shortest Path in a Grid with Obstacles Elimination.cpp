#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    //DFS, credit to upceric
    int res=INT_MAX;
    void dfs(vector<vector<int>>& grid, int k, int i, int j, int step, vector<vector<int> >&dir
             ,vector<vector<bool>> &vis,vector<vector<vector<int>>> &seen)
    {
        if(seen[i][j][k]<=step) return;
        seen[i][j][k]=step;
        if(i==grid.size()-1 && j==grid[0].size()-1)
        {
            res=min(res,step);return;
        }
        for(int t=0;t<4;t++)
        {
            int x=i+dir[t][0];
            int y=j+dir[t][1];
            if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||vis[x][y]) continue;
            if(grid[x][y]==0 && step+1<seen[x][y][k])
            {
                vis[x][y]=true;
                dfs(grid,k,x,y,step+1,dir,vis,seen);
                vis[x][y]=false;
            }
            else if(grid[x][y]==1 && k>0 && step+1<seen[x][y][k-1])
            {
                vis[x][y]=true;
                dfs(grid,k-1,x,y,step+1,dir,vis,seen);
                vis[x][y]=false;
            }
        }
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
    int m=grid.size(),n=grid[0].size();
    vector<vector<int> > dp(m,vector<int>(n,INT_MAX));
    dp[0][0]=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(i-1>=0) dp[i][j]=min(dp[i][j],dp[i-1][j]);
            if(j-1>=0) dp[i][j]=min(dp[i][j],dp[i][j-1]);
            dp[i][j]+=grid[i][j];
        }
    if(dp[m-1][n-1]<=k) return m+n-2;
        
    vector<vector<int> > dir{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<bool> > vis(m,vector<bool>(n,false));
    vector<vector<vector<int> > > seen(m,vector<vector<int>>(n,vector<int>(k+1,INT_MAX)));
    vis[0][0]=true;
    dfs(grid,k,0,0,0,dir,vis,seen);
    return res==INT_MAX?-1:res;
    }
};


class Solution {
public:
    //TC O(n*k), SC O(n*k)
    int shortestPath(vector<vector<int>>& grid, int k) {
        if(k >= grid.size() + grid[0].size() -2){
            return grid.size() + grid[0].size() -2;
        }
        return findPathBFS(grid, k);
    }
private:
    vector<pair<int, int>> dirs{{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    bool boundaryCheck(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()){
            return false;
        }
        return true;
    }
    int findPathBFS(vector<vector<int>>& grid, int k){
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(), -1));
        queue<vector<int>> toVisit;
        toVisit.push({0, 0, 0, k});//{x, y, step, curK}

        while(!toVisit.empty()){
            auto curCell = toVisit.front();
            toVisit.pop();
            int x = curCell[0], y = curCell[1];

            if(x == grid.size() - 1 && y == grid[0].size() - 1){
                return curCell[2];
            }

            if(grid[x][y] == 1){
                if(curCell[3] > 0){
                    curCell[3]--;
                }else{
                    continue;
                }
            }

            //cycle detection
            if(visited[x][y] != -1 && visited[x][y] >= curCell[3]){
                continue;
            }
            visited[x][y] = curCell[3];

            for(int i = 0; i < dirs.size(); i++){
                int newX = x + dirs[i].first;
                int newY = y + dirs[i].second;
                if(boundaryCheck(grid, newX, newY)){
                    toVisit.push({newX, newY, curCell[2] + 1, curCell[3]});
                }
                
            }
        }
        return -1;
    }
    
};