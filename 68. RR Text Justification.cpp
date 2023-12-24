#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res, tempVec;
        int curLen = 0, n = words.size();
        for(string word:words){
            if(tempVec.size() + curLen + word.size() > maxWidth){
                string temp = "";
                int totalGap = tempVec.size() - 1;
                int totalSpace = maxWidth - curLen;
                if(totalGap == 0){
                    temp = tempVec[0] + string(totalSpace, ' ');
                }else{
                    int spacePerGap = totalSpace/totalGap;
                    int extraSpace = totalSpace%totalGap;
                    for(int i = 0; i < tempVec.size(); i++){
                        temp += tempVec[i];
                        if(i < totalGap){
                            temp += string(spacePerGap, ' ');
                            if(i < extraSpace){
                                temp += string(1, ' ');
                            }
                        }
                    }
                }
                res.push_back(temp);
                tempVec.clear();
                curLen = 0;
            }
            tempVec.push_back(word);
            curLen += word.size();
        }

        string temp = "";
        int trailingSpace = maxWidth - tempVec.size() - curLen + 1;
        int totalGap = tempVec.size() - 1;
        for(int i = 0; i < tempVec.size(); i++){
            temp += tempVec[i];
            if(i < totalGap){
                temp += string(1, ' ');
            }
        }
        temp += string(trailingSpace, ' ');
        res.push_back(temp);

        return res;
    }
};