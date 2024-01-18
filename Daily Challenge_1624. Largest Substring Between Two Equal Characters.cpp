#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        //TC O(s.size()), SC O(1)
        vector<int> indices(26, -1);
        int ans = -1;
        for(int i = 0; i < s.size(); i++){
            if(indices[s[i] - 'a'] != -1){
                ans = max(ans, i - indices[s[i] - 'a'] - 1);
            }else{
                indices[s[i] - 'a'] = i;
            }
        }
        return ans;
    }
};