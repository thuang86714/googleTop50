#include <vector>
#include <numeric>
#include <string>
using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        len = n;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(isSimilar(strs[i], strs[j])){
                    connect(i, j);
                }
            }
        } 
        return len;
    }
private:
    vector<int> parent;
    int len;
    bool isSimilar(const string &a, const string &b){
        int counter = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i] && ++counter > 2){
                return false;
            }
        }
        return true;
    }
    int find(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void connect(int i, int j){
        int iParent = find(i), jParent = find(j);
        if(iParent == jParent){
            return;
        }
        parent[jParent] = iParent;
        len--;
    }
};