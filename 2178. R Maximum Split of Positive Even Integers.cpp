#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum %2){
            return {};
        }
        vector<long long> res;
        long long i = 2, curSum = 0;
        while((curSum + i) <= finalSum){
            res.push_back(i);
            curSum += i;
            i += 2;
        }

        res.back() += finalSum - curSum;

        return res;
    }
};


class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum %2){
            return {};
        }
        vector<long long> tempVec;
        findSplit(2, finalSum, tempVec);
        return res;
    }
private:
    vector<long long> res;
    bool findSplit(long long start, long long finalSum, vector<long long>& tempVec){
        if(finalSum == 0){
            if(tempVec.size() > res.size()){
                res = tempVec;
            }
            return true;
        }

        if(finalSum < 0){
            return false;
        }

        for(int i = start; i <= finalSum; i += 2){
            tempVec.push_back(i);
            if(findSplit(i + 2, finalSum - i, tempVec)){
                return true;
            }
            tempVec.pop_back();
        }

        return false;
    }
};