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
        auto it = interval.upper_bound(left);
        if(it != interval.begin() && prev(it)->second >= left){
            it = prev(it);
        }

        while(it != interval.end() && it->first <= right){
            left = min(it->first, left);
            right = max(it->second, right);
            it = interval.erase(it);
        }
        interval[left] = right;
    }
    //TC O(logn)
    bool queryRange(int left, int right) {
        auto it = interval.upper_bound(left);
        if(it == interval.begin()){
            return false;
        }

        if(prev(it)->second < right){
            return false;
        }

        return true;
    }
    //TC O(n + logn)
    void removeRange(int left, int right) {
        auto it = interval.upper_bound(left);
        if(it != interval.begin() && prev(it)->second >= left){
            it = prev(it);
        }
        vector<pair<int, int>> toAdd;
        while(it != interval.end() &&it->first < right){
            if(it->first < left){
                toAdd.push_back({it->first, left});
            }
            if(it->second > right){
                toAdd.push_back({right, it->second});
            }
            it = interval.erase(it);
        }
        for(auto &p:toAdd){
            interval[p.first] = p.second;
        }
    }
private:
    map<int, int>interval;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */