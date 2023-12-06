#include <vector>
#include <string>
#include <numeric>
using namespace std;

class DisjointSet{
private:
    vector<int> parents;
    int sz;
public:
    DisjointSet(int n){
        makeSet(n);
    }

    void makeSet(int n){
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        sz = n;
    }

    int find(int i){
        if(i != parents[i]){
            parents[i] = find(parents[i]);
        }
        return parents[i];
    }

    void join(int i, int j){
        if(find(i) != find(j)){
            parents[find(i)] = find(j);
            sz--;
        }
    }

    int size(){
        return sz;
    }
};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        //credit to mzchen, Union-Find/Disjoint Set
        DisjointSet ds(strs.size());

        for(int i = 0; i < strs.size(); i++){
            for(int j = i + 1; j < strs.size(); j++){
                if(isSimilar(strs[i], strs[j])){
                    ds.join(i, j);
                }
            }
        }
        return ds.size();
    }
private:
    bool isSimilar(string &A, string &B){
        int counter = 0;
        for(int i = 0; i < A.size(); i++){
            if(A[i] != B[i] && ++counter > 2){
                return false;
            }
        }
        return true;
    }
};