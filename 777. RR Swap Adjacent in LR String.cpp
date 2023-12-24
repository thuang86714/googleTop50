#include <string>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        int sIdx = 0, eIdx = 0, n = start.size();
        while(sIdx < n || eIdx < n){
            while(sIdx < n && start[sIdx] == 'X'){
                sIdx++;
            }
            while(eIdx < n && end[eIdx] == 'X'){
                eIdx++;
            }
            if(start[sIdx] != end[eIdx]){
                return false;
            }
            if(start[sIdx] == 'L' && sIdx < eIdx){
                return false;
            }
            if(start[sIdx] == 'R' && sIdx > eIdx){
                return false;
            }
            sIdx++;
            eIdx++;
        }
        return true;
    }
};