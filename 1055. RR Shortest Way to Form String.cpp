#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int shortestWay(string source, string target) {
        int i = 0, j = 0, res= 0;
        while(i < target.size() && res <= i){
            while(j < source.size() && target[i] != source[j]){
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

        return res <= i? res+1:-1;
    }
};

class Solution {
public:
    int shortestWay(string source, string target) {
        vector<vector<int>> indices(26);
        for(int i = 0; i < source.size(); i++){
          indices[source[i] - 'a'].push_back(i);
        }

        int res = 0;
        for(int i = 0, j = -1; i < target.size();){
          auto charVec = indices[target[i] - 'a'];
          if(charVec.empty()){
            return -1;
          }
          auto it = upper_bound(charVec.begin(), charVec.end(), j);
          if(it == charVec.end()){
            j = -1;
            res++;
          }else{
            i++;
            j = *it;
          }
        }
        return res+1;
    }
};