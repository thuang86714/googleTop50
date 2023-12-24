#include <vector>
using namespace std;

class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) {
        for(int i = 0; i < encoding.size() - 1; i += 2){
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
    vector<pair<int, int>> encoded;
    int curIdx = 0;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */