#include <vector>
#include <queue>
#include <algorithm>
#include <array>
#include <numeric>
using namespace std;

//credit to danbelcher, for precomputing part
static constexpr auto powers = [] {//pre-computing
    array<int, 1001> vals{};
    for (size_t i = 1; i < vals.size(); ++i) {
        int steps = 0;
        for (int j = i; j != 1;) {
            if ((j & 1) == 0) {
                j /= 2;
            } else {
                j = 3 * j + 1;
            }
            
            steps++;
        }
        
        vals[i] = steps;
    }
    
    return vals;
}();

class Solution {
public:
    static int getKth(int lo, int hi, int k) {
        const size_t n = hi - lo + 1;
        std::vector<int> pows(n);
        std::iota(pows.begin(), pows.end(), lo);

        std::nth_element(
            pows.begin(), pows.begin() + k - 1, pows.end(),
            [](int a, int b) {
               return powers[a] == powers[b] ? a < b : powers[a] < powers[b]; 
            });
        
        return pows[k - 1];
    }
};

class Solution {
public:
    //credit to vatsalkesarwani
    int step(int x){   // function to calculate steps
        int c=0;
        while(x!=1){
            c++;
            if(x%2==0){
                x/=2;
            }else {
                x=x*3+1;
            }
        }
        return c;
    }
    int getKth(int lo, int hi, int k) {
        priority_queue <pair<int,int>> p;  // max heap
        for(;lo<=hi;lo++){
            p.push({step(lo),lo});
            if(p.size()>k){
                p.pop();
            } 
        }
        return p.top().second;
    }
};

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        //O(nLog(n) + step(n)), SC O(lo - hi)
        vector<pair<int, int>> res;
        for(int i = lo; i <= hi; i++){
            int steps = countStep(i);
            res.push_back({steps, i});
        }
        sort(res.begin(), res.end());
        return res[k - 1].second;
    }
private:
    int countStep(int num){
        int counter = 0;
        while(num != 1){
            if(num%2){
                num = 3*num+1;
            }else{
                num /= 2;
            }
            counter++;
        }
        return counter;
    }
};