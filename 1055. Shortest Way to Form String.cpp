/*
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.

 

Example 1:

Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".
Example 2:

Input: source = "abc", target = "acdbc"
Output: -1
Explanation: The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.
Example 3:

Input: source = "xyz", target = "xzyxz"
Output: 3
Explanation: The target string can be constructed as follows "xz" + "y" + "xz".
 

Constraints:

1 <= source.length, target.length <= 1000
source and target consist of lowercase English letters.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int shortestWay(string source, string target) {
        int res = 0;
        vector<vector<int>> ch_ids(26);
        for(int j = 0; j < source.size(); j++){
            ch_ids[source[j] - 'a'].push_back(j);
        }

        for(int i = 0, j = -1; i < target.size();){
            vector<int> tempVec = ch_ids[target[i] - 'a'];
            if(tempVec.empty()){
                return -1;
            }
            auto it = upper_bound(tempVec.begin(), tempVec.end(), j);
            if(it == tempVec.end()){
                res++;
                j = -1;
            }else{
                i++;
                j = *it;
            }
        }
        return res + 1;
    }
};


class Solution {
public:
    int shortestWay(string source, string target) {
        //credit to votrubac, TC O(m*n), SC O(1)
        int i = 0, j = 0, res = 0;
        while(i < target.size() && res <= i){
            while(target[i] != source[j] && j < source.size()){
                j++;
            }
            if(j == source.size()){
                j = 0;
                res++;
            }else{
                i++;
                j++;
            }
        } 
        return res <= i? res+1: -1;
    }
};