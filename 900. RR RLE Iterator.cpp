#include <vector>
using namespace std;

class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) {
        for(int i = 0; i < encoding.size(); i += 2){
            if(encoding[i]){
                encoded.push_back({encoding[i], encoding[i + 1]});
            }
        }
    }
    
    int next(int n) {
        for(int i = curIdx; i < encoded.size(); i++){
            if(encoded[i].first >= n){
                encoded[i].first -= n;
                curIdx = i;
                return encoded[i].second;
            }else{
                n -= encoded[i].first;
                encoded[i].first = 0;
            }
        }
        return -1;
    }
private:
    int curIdx = 0;
    vector<pair<int, int>> encoded;
};

class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) {
        seq = encoding;
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
  int curIdx = 0;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */