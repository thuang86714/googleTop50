#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int shortestWay(string source, string target) {
        vector<vector<int>> indices(26);
        for(int j = 0; j < source.size(); j++){
            indices[source[j] - 'a'].push_back(j);
        }
        int res = 0;
        for(int i = 0, j = -1; i < target.size();){
            auto charVec = indices[target[i] - 'a'];
            if(charVec.empty()){
                return -1;
            }
            auto it = upper_bound(charVec.begin(), charVec.end(), j);
            if(it == charVec.end()){//need to reset
                j = -1;
                res++;
            }else{
                i++;
                j = *it;
            }
        }

        return res + 1;
    }
};


class Solution {
public:
    int shortestWay(string source, string target) {
        int i = 0, j = 0, res = 0;
        while(i < target.size() && res <= i){
            while(target[i] != source[j] && j < source.size()){
                j++;
            }
            if(j == source.size()){
                j = 0;
                res++;
            }else{
                i++;
                j++;
            }
        }

        return res <= i? res + 1:-1;
    }
};