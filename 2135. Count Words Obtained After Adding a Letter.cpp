/*
You are given two 0-indexed arrays of strings startWords and targetWords. Each string consists of lowercase English letters only.

For each string in targetWords, check if it is possible to choose a string from startWords and perform a conversion operation on it to be equal to that from targetWords.

The conversion operation is described in the following two steps:

Append any lowercase letter that is not present in the string to its end.
For example, if the string is "abc", the letters 'd', 'e', or 'y' can be added to it, but not 'a'. If 'd' is added, the resulting string will be "abcd".
Rearrange the letters of the new string in any arbitrary order.
For example, "abcd" can be rearranged to "acbd", "bacd", "cbda", and so on. Note that it can also be rearranged to "abcd" itself.
Return the number of strings in targetWords that can be obtained by performing the operations on any string of startWords.

Note that you will only be verifying if the string in targetWords can be obtained from a string in startWords by performing the operations. The strings in startWords do not actually change during this process.

 

Example 1:

Input: startWords = ["ant","act","tack"], targetWords = ["tack","act","acti"]
Output: 2
Explanation:
- In order to form targetWords[0] = "tack", we use startWords[1] = "act", append 'k' to it, and rearrange "actk" to "tack".
- There is no string in startWords that can be used to obtain targetWords[1] = "act".
  Note that "act" does exist in startWords, but we must append one letter to the string before rearranging it.
- In order to form targetWords[2] = "acti", we use startWords[1] = "act", append 'i' to it, and rearrange "acti" to "acti" itself.
Example 2:

Input: startWords = ["ab","a"], targetWords = ["abc","abcd"]
Output: 1
Explanation:
- In order to form targetWords[0] = "abc", we use startWords[0] = "ab", add 'c' to it, and rearrange it to "abc".
- There is no string in startWords that can be used to obtain targetWords[1] = "abcd".
 

Constraints:

1 <= startWords.length, targetWords.length <= 5 * 104
1 <= startWords[i].length, targetWords[j].length <= 26
Each string of startWords and targetWords consists of lowercase English letters only.
No letter occurs more than once in any string of startWords or targetWords.
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;


class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> startDict;
        for(string word: startWords){
            string temp = word;
            sort(temp.begin(), temp.end());
            startDict.insert(temp);
        }

        int counter = 0;
        for(string word: targetWords){
            sort(word.begin(), word.end());
            for(int i = 0; i < word.size(); i++){
                if(startDict.count(word.substr(0, i) + word.substr(i + 1))){
                    counter++;
                    break;
                }
            }
        }
        return counter;
    }
};


class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie *node = this;
        for(char c:word){
            if(!node->next[c]){
                node->next[c] = new Trie();
            }
            node = node->next[c];
        }
        node->isEnd = true;
    }
    
    bool exist(string word) {
        Trie *node = this;
        for(char c:word){
            if(!node->next[c])return false;
            node = node->next[c];
        }
        return node->isEnd;
    }

private:
    bool isEnd = false;
    unordered_map<char, Trie*> next;
};

class Solution {
    //credit to colinyoyo26, with some improvement from myself
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        Trie root;
        for(string word:startWords){
            string temp = word;
            sort(temp.begin(), temp.end());
            root.insert(temp);
        }

        int counter = 0;

        for(string word: targetWords){
            sort(word.begin(), word.end());
            for(int i = 0; i < word.size(); i++){
                if(root.exist(word.substr(0, i) + word.substr(i + 1))){
                    counter++;
                    break;
                }
            }
        }
        return counter;
    }
};


class Solution {
public:
    //TLE, int m = startWords.size(), n = targetWords.size(), i = avg len of startWords, j = avg len of targetWords
    //TC (i*m*j*n), SC O(m + n)
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        vector<vector<int>> startDict, targetDict;
        int ans = 0;
        for(string word: startWords){
            vector<int> tempVec(27, 0);
            for(char c: word){
                tempVec[c - 'a']++;
            }
            tempVec.back() = word.size();
            startDict.push_back(tempVec);
        }

        for(string word: targetWords){
            vector<int> tempVec(27, 0);
            for(char c: word){
                tempVec[c - 'a']++;
            }
            tempVec.back() = word.size();
            targetDict.push_back(tempVec);
        }

        for(auto &target: targetDict){
            for(auto &start: startDict){
                if(target.back() != start.back() + 1){
                    continue;
                }
                int diff = 0, startIsZero = 0;
                for(int i = 0; i < 26; i++){
                    if(target[i] != start[i]){
                        if(start[i] == 0){
                            startIsZero++;
                        }
                        diff++;
                    }
                }
                if(diff == 1 && startIsZero == 1){
                    ans++;
                    break;
                }
            }
            
        }

        return ans;
    }
};