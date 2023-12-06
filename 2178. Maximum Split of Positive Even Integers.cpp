/*
You are given an integer finalSum. Split it into a sum of a maximum number of unique positive even integers.

For example, given finalSum = 12, the following splits are valid (unique positive even integers summing up to finalSum): (12), (2 + 10), (2 + 4 + 6), and (4 + 8). Among them, (2 + 4 + 6) contains the maximum number of integers. Note that finalSum cannot be split into (2 + 2 + 4 + 4) as all the numbers should be unique.
Return a list of integers that represent a valid split containing a maximum number of integers. If no valid split exists for finalSum, return an empty list. You may return the integers in any order.

 

Example 1:

Input: finalSum = 12
Output: [2,4,6]
Explanation: The following are valid splits: (12), (2 + 10), (2 + 4 + 6), and (4 + 8).
(2 + 4 + 6) has the maximum number of integers, which is 3. Thus, we return [2,4,6].
Note that [2,6,4], [6,2,4], etc. are also accepted.
Example 2:

Input: finalSum = 7
Output: []
Explanation: There are no valid splits for the given finalSum.
Thus, we return an empty array.
Example 3:

Input: finalSum = 28
Output: [6,8,2,12]
Explanation: The following are valid splits: (2 + 26), (6 + 8 + 2 + 12), and (4 + 24). 
(6 + 8 + 2 + 12) has the maximum number of integers, which is 4. Thus, we return [6,8,2,12].
Note that [10,2,4,12], [6,2,4,16], etc. are also accepted.
 

Constraints:

1 <= finalSum <= 1010
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        //credit to chandanagrawal23, TC O(finalSum), SC O(1)
        /*
        Take n =14

        i = 2 , crSum = 0 , list = [] (crSum + 2 <= 14 , so push it) , crSum + i = 2 , list = [2]
        i = 4 , crSum = 2 , list = [2] (crSum + 4 <= 14 , so push it) , crSum + i = 6 , list = [2,4]
        i = 6 , crSum = 6 , list = [2,4] (crSum + 6 <= 14 , so push it) , crSum + i = 12 , list = [2,4,6]
        i = 8 , crSum = 12 , list = [2,4,6] (crSum + 8 > 14 , so don't push it , break the loop)
        Now we have crSum = 12 , and we want 14 , so simply add difference (which is 14-12 = 2 ) in the last element of list

        so list = [2,4,6+(14-12)] = [2,4,8]
        */

        if(finalSum %2 == 1){
            return {};
        }

        vector<long long> res;
        long long i = 2;
        long long curSum = 0;
        while((curSum + i) <= finalSum){
            res.push_back(i);
            curSum += i;
            i += 2;
        }

        res.back() += (finalSum - curSum);

        return res;
    }
};


class Solution {
    //credit to rahulvyas09874 (in chandanagrawal23 post), backtracking
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum %2 == 1){
            return {};
        }
        vector<long long> tempVec;
        findSplit(2, finalSum, tempVec);

        return res;
    }
private:
    vector<long long> res;
    bool findSplit(long long start, long long finalSum, vector<long long> &tempVec){
        if(finalSum == 0){
            if(tempVec.size() > res.size()){
                res = tempVec;
            }
            return true;
        }

        if(finalSum < 0){
            return false;
        }

        for(long long i = start; i <= finalSum; i += 2){
            tempVec.push_back(i);
            if(findSplit(i + 2, finalSum - i, tempVec)){
                return true;
            }
            tempVec.pop_back();
        }

        return false;
    }
};