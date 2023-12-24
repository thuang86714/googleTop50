#include <unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        //sliding window;
        unordered_map<char, int> visited;
        int i = 0, j = 0, ans = 0;
        while(i < s.size() && j < s.size()){
            if(!visited.count(s[i])){
                while(j < s.size() &&visited.size() == 2){
                    visited[s[j]]--;
                    if(visited[s[j]] == 0){
                        visited.erase(s[j]);
                    }
                    j++;
                }
                visited[s[i]] = 1;
            }else{
                visited[s[i]]++;
            }
            i++;
            ans = max(ans, i - j);
        }
        return ans;
    }
};