/*
Given a rows x cols screen and a sentence represented as a list of strings, return the number of times the given sentence can be fitted on the screen.

The order of words in the sentence must remain unchanged, and a word cannot be split into two lines. A single space must separate two consecutive words in a line.

 

Example 1:

Input: sentence = ["hello","world"], rows = 2, cols = 8
Output: 1
Explanation:
hello---
world---
The character '-' signifies an empty space on the screen.
Example 2:

Input: sentence = ["a", "bcd", "e"], rows = 3, cols = 6
Output: 2
Explanation:
a-bcd- 
e-a---
bcd-e-
The character '-' signifies an empty space on the screen.
Example 3:

Input: sentence = ["i","had","apple","pie"], rows = 4, cols = 5
Output: 1
Explanation:
i-had
apple
pie-i
had--
The character '-' signifies an empty space on the screen.
 

Constraints:

1 <= sentence.length <= 100
1 <= sentence[i].length <= 10
sentence[i] consists of lowercase English letters.
1 <= rows, cols <= 2 * 104
*/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int ans = 0;
        string sen;
        for (auto& word : sentence) {
            sen += word + " ";
        }

        int len = sen.size(), start = 0;

        for (int i = 0; i < rows; i++) {
            start += cols;
            if (sen[start % len] == ' ') {
                start++;
            } else {
                while (start > 0 && sen[(start-1) % len] != ' ') {
                    start--;
                }
            }
        }

        return start / len;
    }
};


class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        //credit to xiong6 and gfxcc
        unordered_map<int, int> umap;
        int num = 0, n = sentence.size(), start = 0;
        while(rows--){
            int start = num%n;
            if(umap.find(start) == umap.end()){
                int cnt = 0, len = -1;
                while((len = len + 1 + sentence[(start + cnt) % n].size()) <= cols){
                    cnt++;
                }
                umap[start] = cnt;
            }
            num += umap[start];
            
        }
        return num/n;
    }
};


class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        //TLE
        int counter = 0, r = 0, i = 0;
        while(r < rows){
            vector<string> curSentence;
            int curLen = 0;
            while(curSentence.size() + curLen + sentence[i].size() <= cols){
                curSentence.push_back(sentence[i]);
                curLen += sentence[i].size();
                if(i == sentence.size() - 1){
                    counter++;
                    i = 0;
                    continue;
                }
                i++;
            }
            curSentence.clear();
            curLen = 0;
            r++;
        }
        return counter;
    }
};