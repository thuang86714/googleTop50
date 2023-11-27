/*
You are playing a game that contains multiple characters, and each of the characters has two main properties: attack and defense. You are given a 2D integer array properties where properties[i] = [attacki, defensei] represents the properties of the ith character in the game.

A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. More formally, a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.

Return the number of weak characters.

 

Example 1:

Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the other.
Example 2:

Input: properties = [[2,2],[3,3]]
Output: 1
Explanation: The first character is weak because the second character has a strictly greater attack and defense.
Example 3:

Input: properties = [[1,5],[10,4],[4,3]]
Output: 1
Explanation: The third character is weak because the second character has a strictly greater attack and defense.
 

Constraints:

2 <= properties.length <= 105
properties[i].length == 2
1 <= attacki, defensei <= 105
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        //credit to prantik0128, TC O(nlogn), SC O(1)
        sort(properties.begin(), properties.end(), comp);
        int curMax = INT_MIN;
        int ans = 0;
        for(auto &p:properties){
            //cout<<p[0]<<","<<p[1]<<endl;
            if(curMax > p[1]){
                ans++;
            }
            curMax = max(curMax, p[1]);
        }
        return ans;
    }
private:
    static bool comp(vector<int> &A, vector<int> &B){
        if(A[0] != B[0]){
           return A[0] > B[0]; 
        }
        return A[1] < B[1];
    }
};




class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        //TC O(n^2), SC O(n)
        vector<pair<int, pair<int, int>>> sumPair;
        for(auto &vec:properties){//n
            int sum = vec[0] + vec[1];
            sumPair.push_back({sum, {vec[0], vec[1]}});
        }

        sort(sumPair.begin(), sumPair.end());//nlogn
        int ans = 0, n = properties.size();

        for(int i = 0; i < n; i++){
            for(int j = n - 1; j >= 0; j--){
                if(sumPair[i].first == sumPair[j].first){
                    break;
                }
                if((sumPair[i].second.first < sumPair[j].second.first) && (sumPair[i].second.second < sumPair[j].second.second)){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};