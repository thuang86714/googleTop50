#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //TC O(nlong + mlogm), SC O(1)
        int i = 0, j = 0, ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};