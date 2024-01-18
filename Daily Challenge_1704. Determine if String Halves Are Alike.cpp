#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int aCount = 0, bCount = 0, len = s.size();
        for(int i = 0; i < len/2; i++){
            if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u' ){
                aCount++;
            }
        }
        for(int i = len/2; i < len; i++){
            if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u'){
                bCount++;
            }
        }
        return aCount == bCount;
    }
};