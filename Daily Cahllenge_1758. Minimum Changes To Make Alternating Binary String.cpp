#include <string>
using namespace std;

class Solution{
public:
    int minOperations(string s) {
        //credit to votrubac, TC O(n), SC O(1)
        int res = 0, sz = s.length();
        for (int i = 0; i < sz; ++i)
            res += s[i] - '0' != i % 2;
        return min(res, sz - res);
    } 
};


class Solution {
public:
    int minOperations(string s) {
        //TC O(n), SC O(1)
        int zero = 0, one = 1;
        for(int i = 1; i < s.size(); i++){
            if(i%2){
                if(s[i] == s[0]){
                    zero++;
                }
            }else{
                if(s[i] != s[0]){
                    zero++;
                }
            }
        }
        
        if(s[0] == '0'){
            s[0] = '1';
        }else{
            s[0] = '0';
        }

        for(int i = 1; i < s.size(); i++){
            if(i%2){
                if(s[i] == s[0]){
                    one++;
                }
            }else{
                if(s[i] != s[0]){
                    one++;
                }
            }
        }
        return min(zero, one);
    }
};