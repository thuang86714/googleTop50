#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(findWord(board, word, i, j, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
private:
    vector<pair<int, int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool findWord(vector<vector<char>>& board, string word, int x, int y, int idx){
        if(board[x][y] != word[idx]){
            return false;
        }
        if(idx == word.size() - 1){
            return true;
        }
        
        char temp = board[x][y];
        board[x][y] = '#';
        for(int i = 0; i < dirs.size(); i++){
            int newX = x + dirs[i].first, newY = y + dirs[i].second;
            if(newX < 0 || newY < 0 || newX >= board.size() || newY >= board[0].size()){
                continue;
            }
            if(findWord(board, word, newX, newY, idx + 1)){
                return true;
            }
        }
        board[x][y] = temp;
        return false;
    }
};