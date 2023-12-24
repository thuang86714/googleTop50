#include <string>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;


class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> dict{bank.begin(), bank.end()};
        if(!dict.count(endGene)){
            return -1;
        }
        queue<string> toVisit;
        toVisit.push(startGene);
        int step = 0;
        while(!toVisit.empty()){
            int len = toVisit.size();
            for(int i = 0; i < len; i++){
                string curGene = toVisit.front();
                toVisit.pop();

                if(curGene == endGene){
                    return step;
                }
                dict.erase(curGene);

                for(int j = 0; j < 8; j++){
                    char temp = curGene[j];
                    for(int k = 0; k < 4; k++){
                        curGene[j] = geneBank[k];
                        if(dict.count(curGene)){
                            toVisit.push(curGene);
                        }
                    }
                    curGene[j] = temp;
                }
            }
            step++;
        }
        return -1;
    }
private:
    vector<char>geneBank {'A', 'T', 'C', 'G'};
};