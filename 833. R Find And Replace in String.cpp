#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        //credit to lee215 + myself, TC O(SN)
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
                    match.erase(idx);//avoid redundant cal(to pass test case 56)
                    break;
                }
            }
            //string sub = sources[pair.second], target = targets[pair.second];
            
        }

        return s;
    }
};