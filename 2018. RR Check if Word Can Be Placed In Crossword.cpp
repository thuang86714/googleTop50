#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<char>> transposed(n, vector<char> (m));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                transposed[j][i] = board[i][j];
            }
        }

        return canPlace(board, word) || canPlace(transposed, word);
    }
private:
    bool canPlace(vector<vector<char>>& grid, string word){
        int n = grid[0].size(), j = 0;
        for(auto &row:grid){
            for(int col = 0; col < n;){
                while(col < n && row[col] == '#'){
                    col++;
                }
                int start = col;
                while(col < n && row[col] != '#'){
                    col++;
                }
                if(canFit(row, start, col - 1, word)){
                    return true;
                }
            }
        }
        return false;
    }

    bool canFit(vector<char> curRow, int start, int end, string word){
        if(end - start + 1 != word.size()){
            return false;
        }
        int i = 0, len = word.size();
        for(; i < len; i++){//from left to right
            if(curRow[i + start] != ' '){
                if(curRow[i + start] != word[i]){
                    break;
                }
            }
        }
        if(i == len){
          return true;
        }

        i = 0;
        for(; i < len; i++){//from left to right
            if(curRow[end - i] != ' '){
                if(curRow[end - i] != word[i]){
                    break;
                }
            }
        }
        return i == len;
    }
};