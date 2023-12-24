#include <vector>
#include <cmath>
using namespace std;

class DetectSquares {
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        sqrs[x][y]++;
        pairs.push_back({x, y});
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1], ans = 0;
        for(const auto &[x3, y3]:pairs){
            if(abs(x1- x3) != 0 &&abs(x1 - x3) == abs(y1 - y3)){
                ans += sqrs[x1][y3]*sqrs[x3][y1];
            }
        }
        return ans;
    }
private:
    int sqrs[1001][1001] = {};
    vector<pair<int, int>> pairs;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */