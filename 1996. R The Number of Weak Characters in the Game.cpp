#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    //credit to tr1nity
    // the idea is to
    // 1. rearrange the order of attack and defense
    // 2. count weak characters (those defenses less than the current maximum defense)
    // 3. update the maximum defense
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        // the final answer to be returned
        int weakCharacters = 0;
        // record maximum defense. since 1 <= defense_i <= 10 ^ 5
        // we can set the init value to x where x < 1
        int maxDefense = 0;
        // use a hash map to map the attack and defense with greater<int> as a key_compare
        map<int, vector<int>, greater<int>> m;
        for(auto &x : p) m[x[0]].push_back(x[1]);
        // for each attack
        for(auto &x : m) {
            // we count the number of weak characters 
            // and add it to `weakCharacters`
            weakCharacters += count_if(x.second.begin(), x.second.end(), [&](int curDefense){ return curDefense < maxDefense;});
            // then update `maxDefense` which is the maximum value in current defenses
            maxDefense = max(maxDefense, *max_element(x.second.begin(), x.second.end()));
        }
        return weakCharacters;
    }
};


class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        auto cmp = [](vector<int> &A, vector<int> &B){
        if(A[0] != B[0]){
            return A[0] > B[0];
        }
        return A[1] < B[1];
        };
        sort(properties.begin(), properties.end(), cmp);
        int curMax = INT_MIN;
        int counter = 0;
        for(int i = 0; i < properties.size(); i++){
            if(properties[i][1] < curMax){
                counter++;
            }
            curMax = max(curMax, properties[i][1]);
        }
        return counter;
    }
};

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        //TC O(nlogn), SC O(1)
        sort(properties.begin(), properties.end(), cmp);
        int curMax = INT_MIN;
        int counter = 0;
        for(int i = 0; i < properties.size(); i++){
            if(properties[i][1] < curMax){
                counter++;
            }
            curMax = max(curMax, properties[i][1]);
        }
        return counter;
    }
private:
    static bool cmp(vector<int> &A, vector<int> &B){
        if(A[0] != B[0]){
            return A[0] > B[0];
        }
        return A[1] < B[1];
    } 
};