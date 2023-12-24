#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        num = numCourses;
        graph.resize(numCourses);
        inComingDegree.resize(numCourses, 0);
        buildGraph(prerequisites);

        while(!zeroIncomingDegree.empty()){
            int node = zeroIncomingDegree.front();
            zeroIncomingDegree.pop();

            for(auto nextNode:graph[node]){
                if(--inComingDegree[nextNode] == 0){
                    zeroIncomingDegree.push(nextNode);
                    num--;
                    res.push_back(nextNode);
                }
            }
        }
        if(num == 0){
            return res;
        }else{
            return {};
        }
    }
private:
    int num;
    vector<int> res;
    vector<vector<int>> graph;
    vector<int> inComingDegree;
    queue<int> zeroIncomingDegree;
    void buildGraph(vector<vector<int>>& prerequisites){
        for(auto &pre:prerequisites){
            graph[pre[1]].push_back(pre[0]);
            inComingDegree[pre[0]]++;
        }
        for(int i = 0; i < inComingDegree.size(); i++){
            if(inComingDegree[i] == 0){
                zeroIncomingDegree.push(i);
                num--;
                res.push_back(i);
            }
        }
    }
};