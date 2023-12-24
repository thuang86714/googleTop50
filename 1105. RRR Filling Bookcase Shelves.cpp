#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        return findMinHeight(books, shelfWidth, 0);
    }
private:
    int memo[1001] = {};
    int findMinHeight(vector<vector<int>>& books, int width, int idx){
        if(memo[idx]){
            return memo[idx];
        }

        if(idx == books.size()){
            return 0;
        }

        int height = INT_MAX;
        int curIdx = idx;
        int curLevelHeight = books[idx][1];
        int curWidth = width;
        while(curIdx < books.size() && curWidth - books[curIdx][0] >= 0){
            curWidth -= books[curIdx][0];
            curLevelHeight = max(curLevelHeight, books[curIdx][1]);
            height = min(height, curLevelHeight + findMinHeight(books, width, ++curIdx));
        }

        return memo[idx] = height;
    }
};