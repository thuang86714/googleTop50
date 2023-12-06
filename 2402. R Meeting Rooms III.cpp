#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        //credit to votrubac, TC O(mlogm), SC O(n), where m = meetings.size();
        vector<int> counter(n, 0);
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> occupied;
        for(int i = 0; i < n; i++){
            available.push(i);
        }

        for(auto &m:meetings){
            while(!occupied.empty() && occupied.top().first <= m[0]){
                available.push(occupied.top().second);
                occupied.pop();
            }

            long long start = available.empty()? occupied.top().first:m[0];
            long long duration = m[1] - m[0];
            int roomNum = available.empty()? occupied.top().second:available.top();

            if(available.empty()){
                occupied.pop();
            }else{
                available.pop();
            }
            counter[roomNum]++;
            occupied.push({start + duration, roomNum});
        }
        return max_element(counter.begin(), counter.end()) - counter.begin();
    }
};