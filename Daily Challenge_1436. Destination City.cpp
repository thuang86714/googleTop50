#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, vector<int>> graph;
        for(auto &path:paths){
            graph[path[0]].push_back(0);
            graph[path[1]].push_back(1);
        }

        for(auto &it:graph){
            if(it.second.size() == 1 && it.second[0] == 1){
                return it.first;
            }
        }

        return "";
    }
};

class Solution {
public:
  string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> degreeMap;        
        for(auto& e: paths){
            degreeMap[e[0]] += 1;
            degreeMap[e[1]] += 0;
        }
        
        for (auto& [k, v]: degreeMap)
            if (v == 0)
                return k;
        return ""; // Note1:
    }
};
/*
Note1: without this, C++ will issue warning:
fatal error: control may reach end of non-void function
*/

class Solution {
public:
  string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> m;
        for(auto& e: paths)     m[e[0]] = e[1];
        string cur(paths[0][0]);
        while(m.count(cur))
            cur = m[cur];
        return cur;
    }
};

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> _set;
        for(int i = 0; i < paths.size(); i++){
            _set.insert(paths[i][0]);
        }
        for(int i = 0; i < paths.size(); i++){
            if(_set.find(paths[i][1]) == _set.end()) return paths[i][1];
        }
        return "";
    }
};