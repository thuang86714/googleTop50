#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        //TC O(n), SC O(n)
        unordered_set<int> occurences;
        unordered_map<int, int> countTracker;
        for(int num:arr){
            countTracker[num]++;
        }
        for(auto &it:countTracker){
            if(occurences.count(it.second)){
                return false;
            }
            occurences.insert(it.second);
        }
        return true;
    }
};