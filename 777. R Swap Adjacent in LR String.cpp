#include <string>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        //credit to TusharBhart, TC O(start.size()), SC O(1)
        int i = 0, j = 0, n = start.size();
        while(i < n || j < n){
            while(i < n && start[i] == 'X'){
                i++;
            }
            while(j < n && end[j] == 'X'){
                j++;
            }

            if(start[i] != end[j]){
                return false;
            }

            if(start[i] == 'L' && i < j){//"XL" --> "LX"
                return false;
            }

            if(start[i] == 'R' && i > j){//"RX" --> "XR"
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};