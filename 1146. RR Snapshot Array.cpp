#include <vector>
#include <map>
using namespace std;

class SnapshotArray {
public:
    SnapshotArray(int length) {
        log.resize(length);
    }
    
    void set(int index, int val) {
        log[index][counter] = val;
    }
    
    int snap() {
        return counter++;
    }
    
    int get(int index, int snap_id) {
        auto it = log[index].upper_bound(snap_id);
        if(it == log[index].begin()){
            return 0;
        }else{
            return prev(it)->second;
        }
    }
private:
    vector<map<int, int>> log;
    int counter = 0;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */