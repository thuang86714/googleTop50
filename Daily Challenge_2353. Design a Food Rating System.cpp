#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
using namespace std;


struct cmp {
    //credit to xxvvpp
 //use const for return type and parameters for both
 bool operator() (const pair<int,string> &a,const pair<int,string> &b) const {        
       if(a.first==b.first) return a.second<b.second;
       return a.first>b.first;
 }
 };

class FoodRatings {
unordered_map<string,int> food_rating;
unordered_map<string,string> food_cus;
unordered_map<string,set<pair<int,string>,cmp>> cus_food_rat;
public:

//O(N)
FoodRatings(vector<string>& a, vector<string>& b, vector<int>& c) {
    int n= a.size();
    for(int i=0;i<n;i++){
        food_cus[a[i]]= b[i];
        food_rating[a[i]]= c[i]; 
        cus_food_rat[b[i]].insert({c[i],a[i]});
    }
}

//O(logn)
void changeRating(string f, int R) {
    string cuison= food_cus[f];
    cus_food_rat[cuison].erase({food_rating[f],f});
    cus_food_rat[cuison].insert({R,f});
    food_rating[f]=R;
}

//O(logn)
// *(cfr[c].begin()) -> get first in set
string highestRated(string c) {
    pair<int,string> p= *(cus_food_rat[c].begin());
    return p.second;
}
};


class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        //credit to IAmCoderrr
        for(int i = 0; i < foods.size(); i++){
            menu[cuisines[i]].insert({-ratings[i], foods[i]});
            category[foods[i]] = cuisines[i];
            logs[foods[i]] = -ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        int prevRating = logs[food];
        string curCuisine = category[food];
        menu[curCuisine].erase({prevRating, food});
        menu[curCuisine].insert({-newRating, food});
        logs[food] = -newRating;
    }
    
    string highestRated(string cuisine) {
        pair<int,string> p= *(menu[cuisine].begin());
        return p.second;
    }
private:
    unordered_map<string, int> logs;//<food, rating>
    unordered_map<string, string> category;
    map<string, set<pair<int, string>>> menu;//<cuisine, <rating, food>>
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */