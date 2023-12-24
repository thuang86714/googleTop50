#include <vector>
using namespace std;

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto &[s, e]:logs){
            if(max(start, s) < min(end, e)){
                return false;
            }
        }
        logs.push_back({start, end});
        return true;
    }
private:
    vector<pair<int, int>> logs;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */