/*
You are given an array words of size n consisting of non-empty strings.

We define the score of a string word as the number of strings words[i] such that word is a prefix of words[i].

For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
Return an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i].

Note that a string is considered as a prefix of itself.

 

Example 1:

Input: words = ["abc","ab","bc","b"]
Output: [5,4,3,2]
Explanation: The answer for each string is the following:
- "abc" has 3 prefixes: "a", "ab", and "abc".
- There are 2 strings with the prefix "a", 2 strings with the prefix "ab", and 1 string with the prefix "abc".
The total is answer[0] = 2 + 2 + 1 = 5.
- "ab" has 2 prefixes: "a" and "ab".
- There are 2 strings with the prefix "a", and 2 strings with the prefix "ab".
The total is answer[1] = 2 + 2 = 4.
- "bc" has 2 prefixes: "b" and "bc".
- There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
The total is answer[2] = 2 + 1 = 3.
- "b" has 1 prefix: "b".
- There are 2 strings with the prefix "b".
The total is answer[3] = 2.
Example 2:

Input: words = ["abcd"]
Output: [4]
Explanation:
"abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 = 4.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] consists of lowercase English letters.
*/

#include <vector>
#include <unordered_map>
using namespace std;

struct TrieNode{
    TrieNode *next[26] = {};
    int count = 0;
};

class Solution {
public:
    //credit to kiranpalsingh1806, TC O(n*m), SC O(longest word)
    vector<int> sumPrefixScores(vector<string>& words) {
        for(string word:words){
            insert(word);
        }

        vector<int> res;
        for(string word: words){
            int sum = prefixCount(word);
            res.push_back(sum);
        }

        return res;
    }
private:
    TrieNode root;
    void insert(string word){
        auto node = &root;
        for(char c:word){
            if(!node->next[c - 'a']){
                node->next[c - 'a'] = new TrieNode();
            }
            node->next[c - 'a']->count++;
            node = node->next[c - 'a'];
        }
    }

    int prefixCount(string word){
        auto node = &root;
        int ans = 0;
        for(char c:word){
            ans += node->next[c - 'a']->count;
            node = node->next[c - 'a'];
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        //TLE
        //TC O(n*m*n), SC O(n*m)
        unordered_map<string, int> stringCounter;
        vector<int> ans;
        for(string word: words){
            int counter = 0;
            for(int i = 1; i <= word.size(); i++){
                string tempStr = word.substr(0, i);
                if(stringCounter.find(tempStr) != stringCounter.end()){
                    counter += stringCounter[tempStr];
                }else{
                    int cnt = 0;
                    for(string word: words){
                        if(tempStr == word.substr(0, i)){
                            cnt++;
                        }
                    }
                    stringCounter[tempStr] = cnt;
                    counter += cnt;
                }
            }
            ans.push_back(counter);
        }

        return ans;
    }
};