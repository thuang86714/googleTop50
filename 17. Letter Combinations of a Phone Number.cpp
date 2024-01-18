#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }
        string tempStr = "";
        findCombo(digits, 0, tempStr);
        return res;
    }
private:
    vector<string> res;
    void findCombo(string digits, int idx, string &str){
        if(idx == digits.size()){
            res.push_back(str);
            return;
        }

        for(char c:keyboard[digits[idx]]){
            str += c;
            findCombo(digits, idx + 1, str);
            str.pop_back();
        }
        return;
    }
    unordered_map<char, vector<char>> keyboard{{'0', {}}, {'1', {}}, {'2', {'a', 'b','c'}}, {'3', {'d', 'e', 'f'}}, {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}}, {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}}, {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};
};