#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int ans = 0;
        for(int i = 0; i < intervals.size(); i++){
            if(!minHeap.empty() && minHeap.top() <= intervals[i][0]){
                minHeap.pop();
            }
            minHeap.push(intervals[i][1]);
            ans = max(ans, (int)minHeap.size());
        }
        return ans;
    }
};