#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int count = 0;
        vector<int> charCount(26, 0);
        for(char c:s){
            charCount[c - 'a']++;
        }
        for(char c:t){
            charCount[c - 'a']--;
        }
        for(int num:charCount){
            if(num > 0){
                count += num;
            }
        }
        return count;
    }
};