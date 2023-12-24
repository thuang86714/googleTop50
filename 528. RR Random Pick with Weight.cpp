#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    Solution(vector<int>& w) {
        seq = w;
        for(int i = 1; i < seq.size(); i++){
            seq[i] += seq[i - 1];
        }
    }
    
    int pickIndex() {
        int x = (int)rand()%seq.back();
        auto it = upper_bound(seq.begin(), seq.end(), x);
        return it - seq.begin();
    }
private:
    vector<int> seq;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */