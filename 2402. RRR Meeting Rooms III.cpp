#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> counter(n, 0);
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> occupied;
        for(int i = 0; i < n; i++){
            available.push(i);
        }
        for(auto &meet:meetings){
            while(!occupied.empty() && occupied.top().first <= meet[0]){
                available.push(occupied.top().second);
                occupied.pop();
            }

            long long start, duration = meet[1] - meet[0], room;
            if(available.empty()){
                start = occupied.top().first;
                room = occupied.top().second;
                occupied.pop();
            }else{
                start = meet[0];
                room = available.top();
                available.pop();
            }
            counter[room]++;
            occupied.push({start + duration, room});

        }
        return max_element(counter.begin(), counter.end()) - counter.begin();
    }
};