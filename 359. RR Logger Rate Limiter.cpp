#include <unordered_map>
#include <string>
using namespace std;

class Logger {
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(log[message] > timestamp){
            return false;
        }
        log[message] = timestamp + 10;
        return true;
    }
private:
    unordered_map<string, int> log;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */