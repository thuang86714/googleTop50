#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //TC O(nlong), SC O(n)
        int ans = 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> logs;
        for(auto &interval:intervals){
            if(logs.empty()){
                logs.push(interval[1]);
            }else{
                if(logs.top() <= interval[0]){
                    logs.pop();   
                }
                logs.push(interval[1]);
            }
            ans = max(ans, (int)logs.size());
        }

        return ans;
    }
};