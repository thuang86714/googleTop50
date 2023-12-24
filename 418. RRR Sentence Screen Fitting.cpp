#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        unordered_map<int, int> strCounter;
        int wordCounter = 0, sz = sentence.size();
        while(rows--){
            int start = wordCounter%sz;
            if(strCounter.find(start) == strCounter.end()){
                int cnt = 0, len = -1;
                while((len = len + 1 + sentence[(start + cnt)%sz].size()) <= cols){
                    cnt++;
                }
                strCounter[start] = cnt;
            }
            wordCounter += strCounter[start];
        }
        return wordCounter/sz;
    }
};