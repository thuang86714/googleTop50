#include <string>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size();
        while(i--){
            if((num[i] - '0')%2){
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};