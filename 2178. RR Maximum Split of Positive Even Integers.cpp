#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2){
            return {};
        }
        vector<long long>res;
        long long curNum = 2;
        long long curSum = 0;
        while(finalSum >= curNum + curSum){
            curSum += curNum;
            res.push_back(curNum);
            curNum += 2;
        }

        res.back() += finalSum - curSum;
        return res;
    }
};


class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        //backtrack
        if(finalSum%2){
          return {};
        }
        vector<long long>tempVec;
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