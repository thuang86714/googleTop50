#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict{wordList.begin(), wordList.end()};
        if(!dict.count(endWord)){
            return 0;
        }
        queue<string> toVisit;
        int step = 1;
        toVisit.push(beginWord);
        while(!toVisit.empty()){
            int len = toVisit.size();
            for(int i = 0; i < len; i++){
                string curStr = toVisit.front();
                toVisit.pop();
                if(curStr == endWord){
                    return step;
                }

                dict.erase(curStr);

                for(int j = 0; j < curStr.size(); j++){
                    char temp = curStr[j];
                    for(int k = 0; k < 26; k++){
                        curStr[j] = k + 'a';
                        if(dict.count(curStr)){
                            toVisit.push(curStr);
                        }
                    }
                    curStr[j] = temp;
                }
            }
            step++;
        }
        return 0;
    }
};