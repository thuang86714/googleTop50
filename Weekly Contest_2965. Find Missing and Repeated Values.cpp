#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> intTracker;
        int n = grid.size();
        for(int i= 1; i <= n*n; i++){
            intTracker.insert(i);
        }
        
        vector<int> res;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(intTracker.find(grid[i][j]) != intTracker.end()){
                    intTracker.erase(grid[i][j]);
                }else{
                    res.push_back(grid[i][j]);
                }
            }
        }
        auto it = intTracker.begin();
        res.push_back(*it);
        return res;
    }
};