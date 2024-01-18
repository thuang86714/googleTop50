#include <string>
#include <vector>
using namespace  std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int curLen = 0;
        vector<string> tempVec;
        for(string word:words){
            if(curLen + tempVec.size() + word.size() > maxWidth){
                string tempStr = "";
                int totalSpaces = maxWidth - curLen;
                if(tempVec.size() == 1){
                    tempStr = tempVec[0] + string(totalSpaces, ' ');
                }else{
                    int totalGap = tempVec.size() - 1;
                    int extraSpace = 0;
                    if(totalSpaces%totalGap != 0){
                        extraSpace = totalSpaces%totalGap;
                    }
                    int spacePerGap = totalSpaces/totalGap;
                    for(int i = 0; i < tempVec.size(); i++){
                        tempStr += tempVec[i];
                        if(i < tempVec.size() -1){
                            tempStr += string(spacePerGap, ' ');
                        }
                        if(i < extraSpace){
                            tempStr += ' ';
                        }
                    }
                }
                res.push_back(tempStr);
                tempVec.clear();
                curLen = 0;
            }
            curLen += word.size();
            tempVec.push_back(word);
        }

        string tempStr = "";
        int totalSpaces = maxWidth - curLen;
        int totalGaps = tempVec.size() - 1;
        int trailingSpace = maxWidth - curLen - tempVec.size() + 1;
        for(int i = 0; i < tempVec.size(); i++){
            tempStr += tempVec[i];
            if(i < totalGaps){
                tempStr += string(1, ' ');
            }
        }
        tempStr += string(trailingSpace, ' ');
        res.push_back(tempStr);

        return res;
    }
};