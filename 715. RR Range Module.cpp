#include <vector>
#include <map>
using namespace std;

class RangeModule {
public:
    RangeModule() {
        //credit to jacklee20499, map + upper_bound
    }
    
    //TC O(n + logn)
    void addRange(int left, int right) {
        auto it = intervalMap.upper_bound(left);

        if(it != intervalMap.begin() && prev(it)->second >= left){
            it = prev(it);
        }

        while(it != intervalMap.end() && it->first <= right){
            left = min(left, it->first);
            right = max(right, it->second);
            it = intervalMap.erase(it);
        }
        intervalMap[left] = right;
    }
    
    //TC O(logn)
    bool queryRange(int left, int right) {
        auto it= intervalMap.upper_bound(left);;
        if(it == intervalMap.begin()){
            return false;
        }

        if(prev(it)->second < right){
            return false;
        }

        return true;
    }
    
    //TC O(n + logn)
    void removeRange(int left, int right) {
        auto it = intervalMap.upper_bound(left);

        if(it != intervalMap.begin() && prev(it)->second >= left){
            it = prev(it);
        }

        vector<pair<int, int>> toAdd;
        while(it != intervalMap.end() && it->first < right){
            if(it->first < left){
                toAdd.push_back({it->first, left});
            }
            if(it->second > right){
                toAdd.push_back({right, it->second});
            }
            it = intervalMap.erase(it);
        }
        for(auto &pair:toAdd){
            intervalMap[pair.first] = pair.second;
        }
    }
private:
    map<int, int> intervalMap;
};