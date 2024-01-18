#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string tempStr = "";
        findParenthesis(n, 0, 0, tempStr);
        return res;
    }
private:
    vector<string> res;
    void findParenthesis(int n, int left, int right, string str){
        if(left == n && right == n){
            res.push_back(str);
        }

        if(left < n){
            findParenthesis(n, left + 1, right, str + "(");
        }
        if(left > right){
            findParenthesis(n, left, right + 1, str + ")");
        }
    }
};