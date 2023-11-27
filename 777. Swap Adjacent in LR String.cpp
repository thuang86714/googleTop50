/*
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

 

Example 1:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: true
Explanation: We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX

Example 2:
Input: start = "X", end = "L"
Output: false
 

Constraints:

1 <= start.length <= 104
start.length == end.length
Both start and end will only consist of characters in 'L', 'R', and 'X'.
*/

#include <string>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        //credit to TusharBhart
        int i = 0, j = 0, m = start.size(), n = end.size();
        while(i < n || j < n){
            while(start[i] == 'X'){
                i++;
            }
            while(end[j] == 'X'){
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


class Solution {
public:
    bool canTransform(string start, string end) {
        //credit to zestypanda
        int n = start.size();
        string startLR, endLR;
        for(int i = 0; i < n; i++){
            if(start[i] != 'X'){
                startLR += start[i];
            }
        }
        for(int i = 0; i < n; i++){
            if(end[i] != 'X'){
                endLR += end[i];
            }
        }

        if(startLR != endLR){
            return false;
        }

        for(int i = 0, j = 0; i < n && j < n;){
            if(start[i] == 'X'){
                i++;
            }else if(end[j] == 'X'){
                j++;
            }else{
                if((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)){
                    return false;
                }
                i++;
                j++;
            }
        }
        return true;
    }
};