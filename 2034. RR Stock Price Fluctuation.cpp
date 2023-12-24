#include <set>
#include <map>
#include <queue>
using namespace std;

class StockPrice {
public:
    StockPrice() {
        
    }
    //TC O(logn)
    void update(int timestamp, int price) {
        if(logs.count(timestamp)){
            int prevPrice = logs[timestamp];
            flunctuation.erase({prevPrice, timestamp});
        }
        logs[timestamp] = price;
        flunctuation.insert({price, timestamp});
    }
    
    //TC O(1)
    int current() {
        auto it = logs.rbegin();
        return (*it).second;
    }
    
    //TC O(1)
    int maximum() {
        auto it = flunctuation.rbegin();
        return (*it).first;
    }
    
    //TC O(1)
    int minimum() {
        auto it = flunctuation.begin();
        return (*it).first;
    }
private:
    set<pair<int, int>> flunctuation;
    map<int, int> logs;
};

class StockPrice {
public:
    StockPrice() {
        
    }
    //O(logn)
    void update(int timestamp, int price) {
        if(timestamp > latestTimeStamp){
            latestTimeStamp = timestamp;
        }
        logs[timestamp] = price;
        maxHeap.push({price, timestamp});//pq.push()->logn
        minHeap.push({price, timestamp});
    }
    //O(1)
    int current() {
        return logs[latestTimeStamp];
    }
    //O(n)
    int maximum() {
        while(!maxHeap.empty()){
            auto currentTop = maxHeap.top();
            if(logs[currentTop.second] == currentTop.first){
                return currentTop.first;
            }
            maxHeap.pop();
        }
        return -1;
    }
    //O(n)
    int minimum() {
        while(!minHeap.empty()){
            auto currentTop = minHeap.top();
            if(logs[currentTop.second] == currentTop.first){
                return currentTop.first;
            }
            minHeap.pop();
        }
        return -1;
    }
private:
    map<int, int> logs;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    priority_queue<pair<int, int>> maxHeap;
    int latestTimeStamp = 0;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */