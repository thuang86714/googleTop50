#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<char>> transposed(n, vector<char>(m));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                transposed[j][i] = board[i][j];
            }
        }

        return canPlace(board, word) || canPlace(transposed, word);
    }
private:
    bool canPlace(vector<vector<char>>& grid, const string word){
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n;){
                while(j < n && grid[i][j] == '#'){
                    j++;
                }
                int start = j;
                while(j < n && grid[i][j] != '#'){
                    j++;
                }
                if(placeWord(grid[i], start, j - 1, word)){
                    return true;
                }
            }
        }
        return false;
    }
    bool placeWord(vector<char> row, int start, int end, const string word){
        if(end - start + 1 != word.size()){
            return false;
        }

        int i = 0, len = word.size();
        for(; i < len; i++){
            if(row[i + start] != ' '){
                if(row[i + start] != word[i]){
                    break;
                }
            }
        }
        if(i == len){
            return true;
        }

        i = 0;
        for(; i < len; i++){
            if(row[end - i] != ' '){
                if(row[end - i] != word[i]){
                    break;
                }
            }
        }
        return i == len;
    }
};