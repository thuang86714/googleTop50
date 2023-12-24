#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> curHave{supplies.begin(), supplies.end()};
        buildGraph(recipes, ingredients, curHave);

        while(!zeroIncomingDegree.empty()){
            string created = zeroIncomingDegree.front();
            zeroIncomingDegree.pop();

            for(string toBeCreated: graph[created]){
                if(--inComingDegree[toBeCreated] == 0){
                    zeroIncomingDegree.push(toBeCreated);
                    res.push_back(toBeCreated);
                }
            }
        }
        return res;
    }
private:
    unordered_map<string, vector<string>> graph;
    queue<string> zeroIncomingDegree;
    vector<string> res;
    unordered_map<string, int> inComingDegree;
    void buildGraph(vector<string>& recipes, vector<vector<string>>& ingredients, unordered_set<string> curHave){
        for(int i = 0; i < recipes.size(); i++){
            int counter = 0;
            for(string &ingre:ingredients[i]){
                if(curHave.count(ingre)){
                    counter++;
                }else{
                    graph[ingre].push_back(recipes[i]);
                }
            }
            if(counter == ingredients[i].size()){
                zeroIncomingDegree.push(recipes[i]);
                res.push_back(recipes[i]);
            }else{
                inComingDegree[recipes[i]] = ingredients[i].size() - counter;
            }
        }
    }

};