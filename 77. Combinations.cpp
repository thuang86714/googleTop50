#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tempVec;
        findCombo(n, k, 1, tempVec);
        return res;
    }
private:
    vector<vector<int>> res;
    void findCombo(int n, int k, int idx, vector<int> &tempVec){
        if(tempVec.size() == k){
            res.push_back(tempVec);
            return;
        }

        for(int i = idx; i <= n; i++){
            tempVec.push_back(i);
            findCombo(n, k, i + 1, tempVec);
            tempVec.pop_back();
        }
        
        return;
    }
};