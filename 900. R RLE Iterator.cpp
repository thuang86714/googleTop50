#include <vector>
using namespace std;

class RLEIterator {
public:
    //credit to Casper-Chen-hku
    RLEIterator(vector<int>& encoding) {
        seq = encoding;
        curIdx = 0;
    }
    
    int next(int n) {
        while(curIdx < seq.size()){
            if(seq[curIdx] >= n){
                seq[curIdx] -= n;
                return seq[curIdx + 1];
            }else{
                n -= seq[curIdx];
                curIdx += 2;
            }
        }
        return -1;
    }
private:
    vector<int> seq;
    int curIdx;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */