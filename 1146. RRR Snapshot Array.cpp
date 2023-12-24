#include <vector>
#include <map>
using namespace std;

class SnapshotArray {
public:
    SnapshotArray(int length) {
        //credit to votrubac
        seq.resize(length);
    }
    
    void set(int index, int val) {//TC O(1)
        seq[index][counter] = val;
    }
    
    int snap() {
        return counter++;
    }
    
    int get(int index, int snap_id) {//TC O(logn), where n is the number of set + snap operations
        auto it = seq[index].upper_bound(snap_id);
        if(it == seq[index].begin()){
            return 0;
        }else{
            return prev(it)->second;
        }
    }
private:
    vector<map<int, int>> seq;
    int counter = 0;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */