#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int>memo;
        int res = 0;
        for(string word:words){
            for(int i = 0; i < word.size(); i++){
                string pre = word.substr(0, i) + word.substr(i + 1);
                memo[word] = max(memo[word], memo.find(pre) == memo.end()?1:memo[pre] + 1);
            }
            res = max(res, memo[word]);
        }
        return res;
    }
private:
    static bool cmp(const string &a, const string &b){
        return a.size() < b.size();
    }
};