#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        //TC O(m*n), n is words.size(), m is avg len of words, SC O(1)
        int ans = 0;
        vector<int> charCounter(26, 0);
        for(char c:chars){
            charCounter[c - 'a']++;
        }
        
        for(string word:words){
            vector<int> copy = charCounter;
            int i = 0;
            for(; i < word.size(); i++){
                if(--copy[word[i] - 'a'] < 0){
                    break;
                }
            }
            if(i == word.size()){
                ans += word.size();
            }
        }
        return ans;
    }
};