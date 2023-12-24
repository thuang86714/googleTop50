#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        //credit to kaju-katli
        int rightOnes = 0, leftZeroes = 0;
        for(char c: s)
            if(c=='1') rightOnes++;
        
        int score = 0;
        for(int i=0; i<s.length()-1; i++){
            if(s[i]=='0') leftZeroes++;
            else rightOnes--;
            score = max(score, leftZeroes + rightOnes);
        }
        return score;
    }
};

class Solution {
public:
    int maxScore(string s) {
        int len = s.size(), counter = 0;
        vector<int> leftCount(len, 0);

        for(int i = 0; i < len; i++){
            if(s[i] == '0'){
                counter++;
            }else{
                counter--;
            }
            leftCount[i] = counter;
        }
        int leftLen;
        if(max_element(leftCount.begin(), leftCount.end()) - leftCount.begin() == s.size() - 1){
            leftLen = s.size() - 1;
        }else{
            leftLen = 1 + max_element(leftCount.begin(), leftCount.end()) - leftCount.begin();
        }

        string leftStr = s.substr(0, leftLen);
        string rightStr = s.substr(leftLen);
        int ans = 0;
        for(int i = 0; i < leftStr.size(); i++){
            if(leftStr[i] == '0'){
                ans++;
            }
        }

        for(int i = 0; i < rightStr.size(); i++){
            if(rightStr[i] == '1'){
                ans++;
            }
        }

        return ans;
    }
};