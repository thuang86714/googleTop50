#include <vector>
#include <cmath>
using namespace std;

class DetectSquares {
public:
    DetectSquares() {
        //credit to hiepit, SC O(n)
    }
    
    //TC O(1)
    void add(vector<int> point) {
        countPoint[point[0]][point[1]]++;
        points.push_back({point[0], point[1]});
    }
    
    //TC O(n)
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1], ans = 0;
        for(const auto &[x3, y3]:points){
            if(abs(x1 - x3) != 0 && abs(x1 - x3) == abs(y1 - y3)){
                ans += countPoint[x1][y3]*countPoint[x3][y1];
            }
        }
        return ans;
    }
private:
    int countPoint[1001][1001] = {};
    vector<pair<int, int>>points;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */