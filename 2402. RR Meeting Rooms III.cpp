#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> occupied;
        vector<int> counter(n, 0);
        for(int i = 0; i < n; i++){
            available.push(i);
        }

        for(auto &meeting:meetings){
            while(!occupied.empty() && occupied.top().first <= meeting[0]){
                available.push(occupied.top().second);
                occupied.pop();
            }

            long long start;
            int room;
            if(available.empty()){
                start = occupied.top().first;
                room = occupied.top().second;
                occupied.pop();
            }else{
                start = meeting[0];
                room = available.top();
                available.pop();
            }
            long long duration = meeting[1] - meeting[0];
            counter[room]++;
            occupied.push({start + duration, room});
            
        }

        return max_element(counter.begin(), counter.end()) - counter.begin();
    }
};