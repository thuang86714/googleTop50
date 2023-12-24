#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        //TC O(nlogn), SC O(1)
        sort(properties.begin(), properties.end(), cmp);
        int len = properties.size();
        int curMax = 0, ans = 0;
        for(int i = 0; i < len; i++){
            if(curMax > properties[i][1]){
                ans++;
            }
            curMax = max(curMax, properties[i][1]);
        }
        return ans;
    }
private:
    static bool cmp(vector<int> &A, vector<int> &B){
        if(A[0] == B[0]){
            return A[1] < B[1];
        }
        return A[0] > B[0];
    }
};