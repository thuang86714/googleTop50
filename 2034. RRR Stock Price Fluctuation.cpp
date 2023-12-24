#include <map>
#include <set>
using namespace std;

class StockPrice {
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(logs.count(timestamp)){
            int prevPrice = logs[timestamp];
            priceTracker.erase({prevPrice, timestamp});
        }
        logs[timestamp] = price;
        priceTracker.insert({price, timestamp});
    }
    
    int current() {
        auto it = logs.rbegin();
        return (*it).second;
    }
    
    int maximum() {
        auto it = priceTracker.rbegin();
        return (*it).first;
    }
    
    int minimum() {
        auto it = priceTracker.begin();
        return (*it).first;
    }
private:
    map<int, int> logs;//<timestamp, price>
    set<pair<int, int>> priceTracker;//<price, timestamp>
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */