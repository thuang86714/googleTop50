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

            for(auto &recipe:graph[created]){
                if(--inComingDegree[recipe] == 0){
                    zeroIncomingDegree.push(recipe);
                    res.push_back(recipe);
                    inComingDegree.erase(recipe);
                }
            }
        }
        return res;
    }
private:
    unordered_map<string, unordered_set<string>> graph;
    unordered_map<string, int> inComingDegree;
    queue<string> zeroIncomingDegree;
    vector<string> res;
    void buildGraph(vector<string>& recipes, vector<vector<string>>& ingredients, unordered_set<string> curHave){
        for(int i = 0; i < recipes.size(); i++){
            int counter = 0;
            for(string ingredient:ingredients[i]){
                graph[ingredient].insert(recipes[i]);
                if(curHave.count(ingredient)){
                    counter++;
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