#include <vector>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if(arr.size() ==1){
            return arr[0];
        }
        int len = arr.size(), curNum = -1, counter;
        for(int i = 0; i < len; i++){
            if(curNum == arr[i]){
                if(++counter >= len/4){
                    return curNum;
                }
            }else{
                curNum = arr[i];
                counter = 0;
            }
        }
        return -1;
    }
};