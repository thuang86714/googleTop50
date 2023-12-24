#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool differByOne(vector<string>& dict) {
        for(int i = 0; i < dict.size(); i++){
            for(int j = i + 1; j < dict.size(); j++){
                if(countDiff(dict[i], dict[j])){
                    return true;
                }
            }
        }
        return false;
    }
private:
    int countDiff(const string &a, const string &b){
        int counter = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i] && ++counter > 1){
                return false;
            }
        }
        return true;
    }
};



class Solution {
public:
    bool differByOne(vector<string>& dict) {
        unordered_map<int, int> hashed;{
            int i = 0;
            for(string &s:dict){
                hashed[getHash(s)] = i++;
            }
        }
        for(string &s:dict){
            int hash = getHash(s);
            int mul = 1;
            for(int i = s.size() - 1; i >= 0; i--){
                for(char c = 'a'; c < 'z'; c++){
                    int cur = (hash - (mul*s[i])%mod + (mul*c)%mod)%mod;
                    if(cur < 0){
                        cur += mod;
                    }
                    if(hash == cur){
                        continue;
                    }
                    if(hashed.find(cur) != hashed.end() && equal(s, dict[hashed[cur]], i)){
                        return true;
                    }
                }
                mul = (base *mul)%mod;
            }
        }
        return false;
    }
private:
    int base = 26;
    int mod = 1e6+7;
    int getHash(string &s){
        int hash = 0;
        for(char c:s){
            hash = ((hash*base)%mod + c)%mod;
        }
        return hash;
    }
    bool equal(const string &s1, const string &s2, int skip){
        for(int i = 0; i < s1.size(); i++){
            if(i == skip){
                continue;
            }
            if(s1[i] != s2[i]){
                return false;
            }
        }
        return true;
    }
};