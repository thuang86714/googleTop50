#include <queue>
using namespace std;

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = lo; i <= hi; i++){
            minHeap.push({calPower(i), i});
        }

        for(int i = 1; i < k; i++){
            minHeap.pop();
        }

        return minHeap.top().second;
    }
private:
    int calPower(int num){
        int step;
        while(num != 1){
            step++;
            if(num%2){
                num = 3*num+1;
            }else{
                num /= 2;
            }
        }
        return step;
    }
};