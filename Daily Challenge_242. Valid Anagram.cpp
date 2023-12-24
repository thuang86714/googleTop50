#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        //edge case: s.size() != t.size()
        //TC O(n), SC O(1)
        vector<int> count(26, 0);//but doesn't fit for follow up
        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a']++;
        }

        for(int i = 0; i < t.size(); i++){
            count[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(count[i] != 0)return false;
        }

        return true;
    }
};