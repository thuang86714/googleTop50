#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        //credit to kreakEmp
    long long ans = LONG_MAX, median = 0, n = nums.size();
    sort(nums.begin(), nums.end());
    median = (n %2 )?nums[n/2]: (nums[n/2] + nums[n/2 - 1])/2;   //find median value
    
    //Find out possible palindroms
    vector<long long> pal;
    string t = to_string(median);
    
    //palidrom with just mirror image of the left half
    for(int i = 0; i < t.size()/2; ++i) t[t.size() - i - 1] = t[i];
    pal.push_back(stoll(t));
    
    //palidrom with mirror image of the left half with left half + 1 
    string pal_next = to_string(stoi(t.substr(0,(t.size()+1)/2)) + 1);
    string temp = pal_next;
    if(temp.size() > (t.size() + 1)/2 ) pal_next = pal_next.substr(0, pal_next.size() - 1);
    if((t.size())%2 ) pal_next = pal_next.substr(0, pal_next.size() - 1);
    reverse(pal_next.begin(), pal_next.end());
    pal.push_back(stoll(temp + pal_next));
    
    //palidrom with mirror image of the left half with left half - 1 
    string pal_prev = to_string(stoi(t.substr(0,(t.size()+1)/2)) - 1);
    temp = pal_prev;
    if(t.size()%2 && temp.size() == (t.size() + 1)/2)  pal_prev = pal_prev.substr(0, pal_prev.size() - 1);
    reverse(pal_prev.begin(), pal_prev.end());
    pal.push_back(stoll(temp + pal_prev));
    
    //check each of palindrom to find the cost and take the min
    for(auto p: pal){
        long long sum = 0; 
        for(auto num: nums) sum += abs(num - p);
        ans = min(ans, sum);
    }
    
    return ans;
}
};