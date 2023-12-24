#include <vector>
#include <set>
using namespace std;

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto &pair:logs){
            if(max(pair.first, start) < min(pair.second, end)){
                return false;
            }
        }
        logs.push_back({start, end});
        return true;
    }
private:
    vector<pair<int, int>> logs;
};

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto &pair:logs){
            if(max(pair.first, start) < min(pair.second, end)){
                return false;
            }
        }
        logs.insert({start, end});
        return true;
    }
private:
    set<pair<int, int>> logs;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */