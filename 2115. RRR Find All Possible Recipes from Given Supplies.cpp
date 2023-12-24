#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        curHave = {supplies.begin(), supplies.end()};
        buildGraph(recipes, ingredients);

        while(!zeroIncomingDegree.empty()){
            string created = zeroIncomingDegree.front();
            zeroIncomingDegree.pop();
            res.push_back(created);
            for(string &food:graph[created]){
                if(--inComingDegree[food] == 0){
                    zeroIncomingDegree.push(food);
                    inComingDegree.erase(food);
                }
            }
        }
        return res;
    }
private:
    vector<string> res;
    unordered_set<string> curHave;
    unordered_map<string, vector<string>> graph;
    queue<string> zeroIncomingDegree;
    unordered_map<string, int> inComingDegree;
    void buildGraph(vector<string>& recipes, vector<vector<string>>& ingredients){
        for(int i = 0; i < recipes.size(); i++){
            int count = 0;
            for(string ingre:ingredients[i]){
                if(curHave.count(ingre)){
                    count++;
                }else{
                    graph[ingre].push_back(recipes[i]);
                }
            }
            if(count == ingredients[i].size()){
                zeroIncomingDegree.push(recipes[i]);
            }else{
                inComingDegree[recipes[i]] = ingredients[i].size() - count;
            }
        }
    }
};