#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        //credit to votrubac
        vector<int> line(50001, 0);
        vector<int> ans(paint.size());
        for(int i = 0; i < paint.size(); i++){
            int startIdx = paint[i][0], endIdx = paint[i][1];
            while(startIdx < endIdx){
                int jump = max(startIdx + 1, line[startIdx]);
                ans[i] += line[startIdx] == 0;
                line[startIdx] = max(line[startIdx], endIdx);
                startIdx = jump;
            }
        }    
        return ans;  
    }
};

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        //credit to votrubac, Sol2, TC O(nlogm), SC O(n), where n is paint.size(), m is the length of painted fence
        vector<int> res;
        map<int, int> intervals;
        for(int i = 0; i < paint.size(); i++){
            int l = paint[i][0], r = paint[i][1];
            auto next = intervals.upper_bound(l), cur = next;
            if(cur != begin(intervals) && prev(cur)->second >= l){
                cur = prev(cur);
                l = cur->second;
            }else{
                cur = intervals.insert({l, r}).first;
            }
            int paint = r - l;
            while(next != end(intervals) && next->first < r){
                paint -= min(r, next->second) - next->first;//deduct overlapped area
                r = max(r, next->second);
                intervals.erase(next++);
            }
            cur->second = max(cur->second, r);//extend the right bound of the cur interval to r
            res.push_back(max(0, paint));
        }
        return res;
    }
};