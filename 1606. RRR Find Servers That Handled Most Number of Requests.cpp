#include <vector>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        //Time complexity: O(n⋅log⁡k), Space complexity: O(k)
        vector<int> counter(k, 0);
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> occupied;
        for(int i = 0; i < k; i++){
            available.push(i);
        }

        for(int i = 0; i < arrival.size(); i++){
            long long start = arrival[i];
            while(!occupied.empty() && occupied.top().first <= start){
                auto [_,serverId] = occupied.top();
                occupied.pop();
                int modified = ((serverId - i)%k + k)%k + i;
                available.push(modified);
            } 

            if(!available.empty()){
                int serverId = available.top()%k;
                available.pop();
                occupied.push({start + load[i], serverId});
                counter[serverId]++;
            }
        }

        int maxi = *max_element(counter.begin(), counter.end());
        vector<int> res;
        for(int i = 0; i < k; i++){
            if(counter[i] == maxi){
                res.push_back(i);
            }
        }
        return res;
    }
};