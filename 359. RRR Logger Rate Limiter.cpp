#include <unordered_map>
#include <string>
using namespace std;

class Logger {
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(logs[message] && logs[message] > timestamp){
            return false;
        }
        logs[message] = timestamp + 10;
        return true;
    }
private:
    unordered_map<string, int> logs;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */