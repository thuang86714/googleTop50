/*
Two strings, X and Y, are considered similar if either they are identical or we can make them equivalent by swapping at most two letters (in distinct positions) within the string X.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

 

Example 1:

Input: strs = ["tars","rats","arts","star"]
Output: 2
Example 2:

Input: strs = ["omv","ovm"]
Output: 1
 

Constraints:

1 <= strs.length <= 300
1 <= strs[i].length <= 300
strs[i] consists of lowercase letters only.
All words in strs have the same length and are anagrams of each other.

*/
#include <vector>
#include <string>
#include <numeric>
using namespace std;

class disjointSet{
    vector<int> parent;
    int sz;
public:
    disjointSet(int n){
        makeset(n);
    }

    void makeset(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz = n;
    }

    int find(int i){
        if(i != parent[i]){
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void join(int i, int j){
        int iParent = find(i), jParent = find(j);
        if(iParent != jParent){
            parent[iParent] = jParent;
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
        //credit to mzchen, disjoint_set
        disjointSet ds(strs.size());

        for(int i = 0; i < strs.size(); i++){
            for(int j = i + 1; j < strs.size(); j++){
                if(similar(strs[i], strs[j])){
                    ds.join(i, j);
                }
            }
        }
        return ds.size();
    }
private:
    bool similar(string &str1, string &str2){
        int n = 0;
        for(int i = 0; i < str1.size(); i++){
            if(str1[i] != str2[i] && ++n > 2){
                return false;
            }
        }
        return true;
    }
};