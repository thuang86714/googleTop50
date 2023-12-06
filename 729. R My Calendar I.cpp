#include <set>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto &pair:calendar){
            if(max(pair.first, start) < min(pair.second, end)){
                return false;
            }
        }
        calendar.push_back({start, end});
        return true;
    }
private:
    vector<pair<int, int>> calendar;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = calendar.lower_bound({start, end});
        if(next != calendar.end() && next->first < end){
            return false;
        }
        if(next != calendar.begin() && start < (--next)->second){
            return false;
        }
        calendar.insert({start, end});
        return true;
    }
private:
    set<pair<int, int>>calendar;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */