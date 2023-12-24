#include <queue>
using namespace std;

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int, int>> maxHeap;
        for(int i = lo; i <= hi; i++){
            maxHeap.push({calPower(i), i});
            if(maxHeap.size() > k){
              maxHeap.pop();
            }
        }
        return maxHeap.top().second;
    }
private:
    int calPower(int n){
        int counter = 0;
        while(n != 1){
            if(n % 2){
                n = 3*n + 1;
            }else{
                n /= 2;
            }
            counter++;
        }
        return counter;
    }
};