#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tempVec;
        findCombo(candidates, target, tempVec, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    void findCombo(vector<int>& candidates, int target, vector<int> &tempVec, int idx){
        if(target <= 0){
            if(target == 0){
                res.push_back(tempVec);
            }
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            tempVec.push_back(candidates[i]);
            findCombo(candidates, target - candidates[i], tempVec, i);
            tempVec.pop_back();
        }
    }
};