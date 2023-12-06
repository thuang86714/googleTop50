#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //TC O(n), SC O(n)
    Solution(vector<int>& w) {
        //credit to ciguvi and Tech Dose
        for(int num:w){
            if(sumVec.empty()){
                sumVec.push_back(num);
            }else{
                sumVec.push_back(sumVec.back() + num);
            }
        }
    }
    
    //TC O(logn), SC O(1)
    int pickIndex() {
        int poolSize = sumVec.back();
        int idx = rand()%poolSize;
        auto it = upper_bound(sumVec.begin(), sumVec.end(), idx);
        return it - sumVec.begin();
    }
private:
    vector<int> sumVec;
};



/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */