#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        //credit to jacklee20499
        int n = books.size();
        int memo[n+1];
        //memset(memo, INT_MAX, sizeof(memo));
        for(int i=0; i<n+1; i++){
            memo[i] = INT_MAX;
        }
        memo[0] = 0;

        for(int i = 1; i <= n; i++){
            int height = 0, width = 0;
            for(int j = i; j > 0; j--){
                width += books[j - 1][0];
                if(width > shelfWidth){
                    break;
                }
                height = max(height, books[j - 1][1]);
                memo[i] = min(memo[i], memo[j - 1] + height);
            }
        }
        return memo[n];
    }
};


class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        //credit to jacklee20499
        memset(memo, -1, sizeof(memo));
        return calHeight(books, shelfWidth, 0);
    }
private:
    int memo[1001];
    int calHeight(vector<vector<int>>& books, int shelfWidth, int idx){
        if(idx == books.size()){
            return 0;
        }
        if(memo[idx] != -1){
            return memo[idx];
        }

        int height = INT_MAX;
        int curLevelHeight = books[idx][1];
        int curBookIdx = idx;
        int curWidth = shelfWidth;
        while(curBookIdx < books.size() && curWidth - books[curBookIdx][0] >= 0){
            curLevelHeight = max(curLevelHeight, books[curBookIdx][1]);
            curWidth -= books[curBookIdx][0];
            height = min(height, curLevelHeight + calHeight(books, shelfWidth, ++curBookIdx));
        }

        return memo[idx] = height;
    }
};