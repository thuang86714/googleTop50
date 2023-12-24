#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    private:
    int getHash(string& s, int base, int mod) {
        //credit to pratickkejriwal, Rabin-Karp
        //Actual time complexity here is O(nm) + O(26*nm) ; Space complexity O(nm)
        int hash = 0;
        for(char c : s)
            hash = ((hash * base)%mod + c) % mod;
        return hash;
    }

    bool equal(string& s1, string& s2, int skip) {
        for(int iter=0; iter<s1.size(); iter++) {
            if (iter == skip) continue;
            if (s1[iter] != s2[iter]) return false;
        }
        return true;
    }

    public:
    bool differByOne(vector<string>& dict) {
        int base = 26, mod = 1e6+7;
        unordered_map<int, int> hashes;
        {
            int i = 0; 
            for(string& s: dict)
                hashes[getHash(s, base, mod)] = i++;
        }
        for(string& s : dict) {
            int hash = getHash(s, base, mod);
            int mul = 1;
            for(int iter=s.size()-1; iter>=0; iter--) {
                for(char c = 'a'; c <= 'z'; c++) {
                    
                    int curr = (hash - (mul*s[iter])%mod + (mul*c)%mod)%mod;
                    if (curr < 0) curr += mod;
                    if (hash == curr) continue;
                    if (hashes.find(curr) != hashes.end() and equal(s, dict[hashes[curr]], iter))
                        return true;
                }
                mul = (base * mul) % mod;
            }
        }
        return false;
    }
};



class Solution {
public:
    bool differByOne(vector<string>& dict) {
        //TC O(n^2*m), SC O(1)
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
    bool countDiff(const string &A, const string &B){
        int counter = 0;
        for(int i = 0; i < A.size(); i++){
            if(A[i] != B[i] && ++counter > 1){
                return false;
            }
        }
        return true;
    }
};