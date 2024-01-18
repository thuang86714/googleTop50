#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        //TC O(n*m) where n is words.size(), and m is avg len of words, SC O(1)
        int n = words.size();
        vector<int> charCounter(26);
        for(string word:words){
            for(char c: word){
                charCounter[c - 'a']++;
            }
        }
        for(auto &it:charCounter){
            if(it%n){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char, int> charCounter;
        for(string word:words){
            for(char c: word){
                charCounter[c]++;
            }
        }
        for(auto &it:charCounter){
            if(it.second%n){
                return false;
            }
        }
        return true;
    }
};