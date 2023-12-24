#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        int ans = 0, curMax = 0;
        sort(properties.begin(), properties.end(), comp);
        for(int i = 0; i < n; i++){
            if(curMax > properties[i][1]){
                ans++;
            }
            curMax = max(curMax, properties[i][1]);
        }
        return ans;
    }
private:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
};