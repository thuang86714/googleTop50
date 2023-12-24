#include <vector>
#include <numeric>
#include <string>
using namespace std;

class UnionFind{
public:
    int len;
    vector<int> parent, rank;
    
    UnionFind(int n){
        len = n;
        parent.resize(n);
        rank.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void connect(int i, int j){
        int iPare = find(i), jPare = find(j);
        if(iPare != jPare){
            if(rank[iPare] > rank[jPare]){
                parent[jPare] = iPare;
            }else if(rank[iPare] < rank[jPare]){
                parent[iPare] = jPare;
            }else{
                parent[iPare] = jPare;
                rank[jPare]++;
            }
            len--;
        }
    }

    int size(){
        return len;
    }
};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        UnionFind uf(n);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(areSimilar(strs[i], strs[j])){
                    uf.connect(i, j);
                }
            }
        }
        return uf.size();
    }
private:
    bool areSimilar(const string &A, const string &B){
        int counter = 0;
        for(int i = 0; i < A.size(); i++){
            if(A[i] != B[i] && ++counter > 2){
                return false;
            }
        }
        return true;
    }
};