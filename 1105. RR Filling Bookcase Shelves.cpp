#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        return findHeight(books, shelfWidth, 0);
    }
private:
    int memo[1001] = {};
    int findHeight(vector<vector<int>>& books, int width, int curIdx){
        if(curIdx == books.size()){
            return 0;
        }
        if(memo[curIdx]){
            return memo[curIdx];
        }
        int height = INT_MAX;
        int curLevelHeight = books[curIdx][1];
        int curBookIdx = curIdx;
        int curWidth = width;
        while(curBookIdx < books.size() && curWidth - books[curBookIdx][0] >= 0){
            curLevelHeight = max(curLevelHeight, books[curBookIdx][1]);
            curWidth -= books[curBookIdx][0];
            height = min(height, curLevelHeight + findHeight(books, width, ++curBookIdx));
        } 

        return memo[curIdx] = height;
    }
};