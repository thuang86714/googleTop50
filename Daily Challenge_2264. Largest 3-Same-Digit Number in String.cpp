#include <string>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int ansNum = -1;
        char cur = '#';
        int counter = 1;
        for(int i = 0; i < num.size(); i++){
            if(num[i] == cur){
                counter++;
            }else{
                cur = num[i];
                counter = 1;
            }
            if(counter >= 3){
                ansNum = max(ansNum, cur - '0');
            }
        }

        if(ansNum == -1){
            return "";
        }else{
            return to_string(ansNum) + to_string(ansNum) + to_string(ansNum);
        }
    }
};