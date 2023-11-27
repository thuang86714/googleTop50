/*
Companies
You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.

We want to place these books in order onto bookcase shelves that have a total width shelfWidth.

We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are no more books to place.

Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.

For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.
Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.

 

Example 1:
Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
Output: 6
Explanation:
The sum of the heights of the 3 shelves is 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.
Example 2:

Input: books = [[1,3],[2,4],[3,2]], shelfWidth = 6
Output: 4
 

Constraints:

1 <= books.length <= 1000
1 <= thickness i <= shelfWidth <= 1000
1 <= height i <= 1000
*/
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        //credit to jacklee20499, TC O(m*n), SC O(1)
        int n = books.size();
        for(int i=0; i<1001; i++){
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
private:
    int memo[1001];
};


class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(memo, -1, sizeof(memo));
        return placeBooks(books, shelfWidth, 0);
    }
private:
    int placeBooks(vector<vector<int>>& books, int shelfWidth, int curIdx){
        //credit to jacklee20499, TC O(m*n), SC O(m*n)
        if(curIdx == books.size()){
            return 0;
        }
        if(memo[curIdx] != -1){
            return memo[curIdx];
        }

        int height = INT_MAX;
        int remainingWidth = shelfWidth;
        int currentBookIdx = curIdx;
        int currentLevelHeight = books[curIdx][1];

        while(currentBookIdx < books.size() && remainingWidth - books[currentBookIdx][0] >= 0){
            currentLevelHeight = max(currentLevelHeight, books[currentBookIdx][1]);
            remainingWidth -= books[currentBookIdx][0];
            height = min(height, currentLevelHeight + placeBooks(books, shelfWidth, ++currentBookIdx));
        }

        return memo[curIdx] = height;
    }
    int memo[1001];
};

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        //credit to jacklee20499, TLE
        return calculateMinHeight(books, shelfWidth, 0);
    }
private:
    int calculateMinHeight(vector<vector<int>>& books, int shelfWidth, int cur) {
        if(cur == books.size()) return 0;
        
        int height = INT_MAX; 
        
        int remainingWidth = shelfWidth; 
        int currentBookIndex = cur; 
        int currentShelfHeight = books[currentBookIndex][1]; 

        while(currentBookIndex < books.size() && remainingWidth - books[currentBookIndex][0] >= 0) {
            currentShelfHeight = max(books[currentBookIndex][1], currentShelfHeight);
            remainingWidth -= books[currentBookIndex][0];
            height = min(height, currentShelfHeight + calculateMinHeight(books, shelfWidth, ++currentBookIndex));
            
        }
        
        return height; 
    }
};