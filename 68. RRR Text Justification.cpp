#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0, curLen = 0;
        vector<string> res, tempVec;
        while(i < words.size()){
            if(tempVec.size() + words[i].size() + curLen <= maxWidth){
                curLen += words[i].size();
                tempVec.push_back(words[i]);
                i++;
            }else{
                string tempStr = "";
                if(tempVec.size() == 1){
                    int totalSpaces = maxWidth - tempVec[0].size();
                    tempStr = tempVec[0] + string(totalSpaces, ' ');
                }else{
                    int totalSpaces = maxWidth - curLen;
                    int totalGaps = tempVec.size() - 1;
                    int spacePerGap = totalSpaces/totalGaps;
                    int extraSpace = 0;
                    if(totalSpaces%totalGaps){
                        extraSpace = totalSpaces%totalGaps;
                    }
                    for(int i = 0; i < tempVec.size(); i++){
                        if(i != tempVec.size() - 1){
                            tempStr = tempStr + tempVec[i] + string(spacePerGap, ' ');
                        }else{
                            tempStr = tempStr + tempVec[i];
                        }
                        if(i < extraSpace){
                            tempStr += ' ';
                        }
                    }
                }
                tempVec.clear();
                curLen = 0;
                res.push_back(tempStr);
            }
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