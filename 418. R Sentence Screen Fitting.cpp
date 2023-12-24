#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        //credit to xiong6 and gfxcc
        unordered_map<int, int> strCounter;
        int num = 0, sz = sentence.size();
        while(rows--){
            int startIdx = num%sz;
            if(strCounter.find(startIdx) == strCounter.end()){
                int cnt = 0, len = -1;
                while((len = len + 1 + sentence[(startIdx + cnt)%sz].size()) <= cols){
                    cnt++;
                }
                strCounter[startIdx] = cnt;
            }
            num += strCounter[startIdx];
        }
        return num/sz;
    }
};