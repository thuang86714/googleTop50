#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        unordered_map<int, vector<int>> match;
        for(int i = 0; i < indices.size(); i++){
            match[indices[i]].push_back(i);
        }
        sort(indices.rbegin(), indices.rend());
        for(auto &idx:indices){
            for(int num:match[idx]){
                string sub = sources[num], target = targets[num];
                if(s.substr(idx, sub.size()) == sub){
                    s = s.substr(0, idx) + target + s.substr(idx + sub.size());
                    match.erase(idx);
                    break;
                }
            }
        }
        return s;
    }
};