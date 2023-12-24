#include <string>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0, j = 0;
        while(i < start.size() || j < end.size()){
            while(i < start.size() && start[i] == 'X'){
                i++;
            }
            while(j < end.size() && end[j] == 'X'){
                j++;
            }
            if(start[i] != end[j]){
                return false;
            }

            if(start[i] == 'L' && i < j){
                return false;
            }

            if(start[i] == 'R' && i > j){
                return false;
            }
            i++;
            j++;
        }

        return true;
    }
};