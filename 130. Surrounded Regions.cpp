#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //DFS
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                findODFS(board, i, 0);
            }
            if(board[i][n - 1] == 'O'){
                findODFS(board, i, n - 1);
            }
        }

        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                findODFS(board, 0, j);
            }
            if(board[m - 1][j] == 'O'){
                findODFS(board, m - 1, j);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }else{
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    vector<pair<int, int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void findODFS(vector<vector<char>>& board, int x, int y){
        board[x][y] = '#';

        for(int i = 0; i < dirs.size(); i++){
            int newX = x + dirs[i].first, newY = y + dirs[i].second;
            if(newX < 0 || newY < 0 || newX >= board.size() || newY >= board[0].size() || board[newX][newY] != 'O'){
                continue;
            }
            findODFS(board, newX, newY);
        }
    }
};