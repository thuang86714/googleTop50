/*
The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:

if x is even then x = x / 2
if x is odd then x = 3 * x + 1
For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, if two or more integers have the same power value sort them by ascending order.

Return the kth integer in the range [lo, hi] sorted by the power value.

Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is will fit in a 32-bit signed integer.

 

Example 1:

Input: lo = 12, hi = 15, k = 2
Output: 13
Explanation: The power of 12 is 9 (12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1)
The power of 13 is 9
The power of 14 is 17
The power of 15 is 17
The interval sorted by the power value [12,13,14,15]. For k = 2 answer is the second element which is 13.
Notice that 12 and 13 have the same power value and we sorted them in ascending order. Same for 14 and 15.
Example 2:

Input: lo = 7, hi = 11, k = 4
Output: 7
Explanation: The power array corresponding to the interval [7, 8, 9, 10, 11] is [16, 3, 19, 6, 14].
The interval sorted by power is [8, 10, 11, 7, 9].
The fourth number in the sorted array is 7.
 

Constraints:

1 <= lo <= hi <= 1000
1 <= k <= hi - lo + 1
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> res;
        for(int i = lo; i <= hi; i++){
            int steps = countSteps(i);
            res.push_back({steps, i});
        }
        sort(res.begin(), res.end());

        return res[k - 1].second;
    }
private:
    int countSteps(int num){
        int counter = 0;;
        while(num != 1){
            if(num %2){
                num = 3*num + 1;
            }else{
                num /= 2;
            }
            counter++;
        }
        return counter;
    }
};

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> res;
        for(int i = lo; i <= hi; i++){
            int sum = countSteps(i);
            res.push_back({sum, i});
        }
        sort(res.begin(), res.end());
        int sum;
        for(int i = 0; i < k; i++){
            sum = res[i].second;
        }

        return sum;
    }
private:
    unordered_map<int, int> steps;
    int countSteps(int num){
        int counter = 0;
        if(steps.count(num)){
            return steps[num];
        }
        vector<int> toVisit;
        toVisit.push_back(num);
        while(num != 1){
            counter++;
            if(num%2){
                num = 3*num + 1;
            }else{
                num /= 2;
            }
            
            if(num != 1){
                toVisit.push_back(num);
            }
        }
        int n = toVisit.size();
        for(int i = n - 1; i >= 0; i--){
            steps[toVisit[i]] = counter - i;
        }
        return counter;
    }
};