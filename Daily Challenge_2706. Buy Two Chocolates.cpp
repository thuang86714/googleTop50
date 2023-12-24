#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        if(prices.size() == 1){
            if(prices[0] > money){
                return money;
            }else{
                return money - prices[0];
            }
        }
        sort(prices.begin(), prices.end());
        if(prices[0] + prices[1] > money){
            return money;
        }else{
            return money - prices[0] - prices[1];
        }
    }
};