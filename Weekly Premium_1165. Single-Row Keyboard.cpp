#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        //TC O(n), SC O(1)
        vector<int> keyNum(26, 0);
        for(int i = 0; i < keyboard.size(); i++){
            keyNum[keyboard[i] - 'a'] = i;
        }
        int prev = 0, ans = 0;
        for(char c:word){
            ans += abs(prev - keyNum[c - 'a']);
            prev = keyNum[c - 'a'];
        }
        return ans;
    }
};