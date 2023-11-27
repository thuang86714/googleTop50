/*
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:
Input: timePoints = ["23:59","00:00"]
Output: 1

Example 2:
Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 

Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".
*/

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& times) {
        //credit to alexander, TC O(nlogn), SC O(1)
        int n = times.size();
        sort(times.begin(), times.end());
        int mindiff = INT_MAX;
        for (int i = 0; i < times.size(); i++) {
            int diff = abs(timeDiff(times[(i - 1 + n) % n], times[i]));
            diff = min(diff, 1440 - diff);
            mindiff = min(mindiff, diff);
        }
        return mindiff;
    }

private:
    int timeDiff(string t1, string t2) {
        int h1 = stoi(t1.substr(0, 2));
        int m1 = stoi(t1.substr(3, 2));
        int h2 = stoi(t2.substr(0, 2));
        int m2 = stoi(t2.substr(3, 2));
        return (h2 - h1) * 60 + (m2 - m1);
    }
};

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        //TC O(nlogn)-->faster, SC O(n)
        vector<int> timeInt;
        for(string time:timePoints){
            int minSum = transformToMin(time);
            timeInt.push_back(minSum);
        }
        sort(timeInt.begin(), timeInt.end());
        int diff = 24*60 - abs(timeInt.front() - timeInt.back());
        for(int i = 1; i < timeInt.size(); i++){
            diff = min(diff, abs(timeInt[i] - timeInt[i - 1]));
        }
        return diff;
    }
private:
    int transformToMin(string time){
        int minSum = 0, tens;
        for(int i = 0; i < time.size(); i++){
            if(i == 0 || i == 3){
                tens = time[i] - '0';
                
            }
            if(i == 1 || i == 4){
                tens *= 10;
                tens += time[i] - '0';
                if(i == 1){
                    tens *= 60;
                    minSum += tens;
                }else{
                    minSum += tens;
                }
            }
        }
        return minSum;
    }
};