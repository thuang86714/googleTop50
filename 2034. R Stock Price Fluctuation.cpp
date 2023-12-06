#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

class StockPrice {
public:
    StockPrice() 
    {
    }
    
    void update(int timestamp, int price) 
    {
        /*if (map1.find(timestamp) != map1.end()) {
            int previous_stock_price = map1[timestamp];
            map2[previous_stock_price] -= 1;
            if (map2[previous_stock_price] == 0)
                map2.erase(previous_stock_price);
        }*/

        if (timestamp > latestTimestamp){
            latestTimestamp = timestamp;
        }
        
        logs[timestamp] = price;
        maxHeap.push({price, timestamp});
        minHeap.push({price, timestamp});
    }
    
    int current() 
    {
        return logs[latestTimestamp];
    }
    
    int maximum() 
    {
        while (!maxHeap.empty()) {
            auto &currentTop = maxHeap.top();
            if (logs[currentTop.second] == currentTop.first)
                return currentTop.first;
            maxHeap.pop();
        }
        return -1;
    }
    
    int minimum() 
    {
        while (!minHeap.empty()) {
            auto &currentTop = minHeap.top();
            if (logs[currentTop.second] == currentTop.first)
                return currentTop.first;
            minHeap.pop();
        }
        return -1;
    }
private:
    unordered_map<int, int> logs;
    std::priority_queue<std::pair<int, int>> maxHeap;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minHeap;
    int latestTimestamp = 0;
};


/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */


class StockPrice {
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(record.count(timestamp)){
            int prevPrice = record[timestamp];
            fluctuation.erase({prevPrice, timestamp});
        }
        record[timestamp] = price;
        fluctuation.insert({price, timestamp});
    }
    
    int current() {
        return (*record.rbegin()).second;
    }
    
    int maximum() {
        return (*fluctuation.rbegin()).first;
    }
    
    int minimum() {
        return (*fluctuation.begin()).first;
    }
private:
    set<pair<int, int>> fluctuation;//<price, time>
    map<int,int> record;//<time, price>
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */