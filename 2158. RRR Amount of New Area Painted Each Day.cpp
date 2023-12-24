#include <vector>
using namespace std;



class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        //jump line, TC O(n + m), SC O(n+m), given the constraint 0 <= starti < endi <= 50000
        vector<int> line(50001), res(paint.size());
        for(int i = 0; i < paint.size(); i++){
            int start = paint[i][0], end = paint[i][1];
            while(start < end){
                int jump = max(start + 1, line[start]);
                res[i] += line[start] == 0;
                line[start] = max(line[start], end);
                start = jump;
            }
        }
        return res;
    }
};