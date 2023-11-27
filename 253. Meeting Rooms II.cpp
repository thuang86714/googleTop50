/*
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1
 

Constraints:

1 <= intervals.length <= 104
0 <= starti < endi <= 106
*/
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //TC O(nlogn), SC O(n)
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int ans = 0;
        for(auto &interval:intervals){
            if(!minHeap.empty() && minHeap.top() <= interval[0]){
                minHeap.pop();
            }
            minHeap.push(interval[1]);
            ans = max(ans, (int)minHeap.size());
        }
        return ans;
    }
};