/*
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 

Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth
*/

#include <string>
#include <vector>
using namespace  std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size(), charSum = 0;
        vector<string> tempVec, res;
        for(string word:words){
            if(tempVec.size() + charSum + word.size() > maxWidth){
                string temp = "";
                int totalGap = tempVec.size() - 1;
                int totalSpace = maxWidth - charSum;
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
                charSum = 0;
            }
            tempVec.push_back(word);
            charSum += word.size();
        }
        string temp = "";
        int trailingSpace = maxWidth - tempVec.size() - charSum + 1;
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
