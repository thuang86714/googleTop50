#include <vector>
using namespace std;

class BinaryMatrix {
public:
    int get(int row, int col);
    vector<int> dimensions();
};


class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        //TC O(m+n), SC O(1)
        int rows = binaryMatrix.dimensions()[0], cols = binaryMatrix.dimensions()[1];
        int i = 0, j = cols - 1;
        while(i < rows && j >= 0){
            if(binaryMatrix.get(i, j)){
                j--;
            }else{
                i++;
            }
        }
        if(j == cols - 1){
            return -1;
        }else{
            return j + 1;
        }
    }
};