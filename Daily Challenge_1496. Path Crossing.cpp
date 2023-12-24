#include <unordered_map>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        //TC O(n)
        unordered_set<string> visited;
        int x = 0, y = 0;
        visited.insert("0,0");
        for(char c:path){
            if(c == 'N'){
                y--;
            }else if(c == 'S'){
                y++;
            }else if(c == 'E'){
                x++;
            }else{
                x--;
            }
            string hashed = to_string(x) + "," + to_string(y);
            if(visited.count(hashed)){
                return true;
            }
            visited.insert(hashed);
        }
        return false;
    }
};


class Solution {
public:
    bool isPathCrossing(string path) {
        //TC O(n^2)
        unordered_map<int, vector<int>> visited;
        int x = 0, y = 0;
        visited[x].push_back(y);
        for(char c:path){
            if(c == 'N'){
                y--;
            }else if(c == 'S'){
                y++;
            }else if(c == 'E'){
                x++;
            }else{
                x--;
            }
            if(visited.count(x) && find(visited[x].begin(), visited[x].end(), y) != visited[x].end()){
                return true;
            }
            visited[x].push_back(y);
        }
        return false;
    }
};