/*
An attendance record for a student can be represented as a string where each character signifies whether the
student was absent, late, or present on that day. The record only contains the following three characters:

'A': Absent.
'L': Late.
'P': Present.
Any student is eligible for an attendance award if they meet both of the following criteria:

The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

 

Example 1:

Input: n = 2
Output: 8
Explanation: There are 8 records with length 2 that are eligible for an award:
"PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
Example 2:

Input: n = 1
Output: 3
Example 3:

Input: n = 10101
Output: 183236316
 

Constraints:

1 <= n <= 105
*/
#include <vector>
using namespace std;

class Solution {
public:
    // Tabulation + Space optimised
    //credit to VAIBHAV_SHORAN
    int checkRecord(int num) {
        vector<vector<int>> prev(2, vector<int> (3, 1)), cur(2, vector<int> (3, 0));

        for(int n = 1; n <= num; n++){
            for(int absent = 0; absent <= 1; absent++){
                for(int late = 0; late <= 2; late++){
                    int A, L, P;
                    A = L = P = 0;

                    if(absent > 0){
                        A = prev[absent - 1][2];
                    }

                    if(late > 0){
                        L = prev[absent][late - 1];
                    }

                    P = prev[absent][2];

                    cur[absent][late] = ((A + L) % MOD + P) % MOD; 
                }
            }
            prev = cur;
        }

        return cur[1][2];
    }
private:
    int MOD = 1e9 + 7;
};


class Solution {
public:
    // Tabulation
    int checkRecord(int num) {
        vector<vector<vector<int>>> memo(num + 1, vector<vector<int>> (2, vector<int> (3, 0)));
        for(int i = 0; i <= 1; i++){
            for(int j = 0; j <= 2; j++){
                memo[0][i][j] = 1;
            }
        }

        for(int n = 1; n <= num; n++){
            for(int absent = 0; absent <= 1; absent++){
                for(int late = 0; late <= 2; late++){
                    int A, L, P;
                    A = L = P = 0;

                    if(absent > 0){
                        A = memo[n - 1][absent - 1][2];
                    }

                    if(late > 0){
                        L = memo[n - 1][absent][late - 1];
                    }

                    P = memo[n - 1][absent][2];

                    memo[n][absent][late] = ((A + L) % MOD + P) % MOD; 
                }
            }
        }

        return memo[num][1][2];
    }
private:
    int MOD = 1e9 + 7;
};


class Solution {
public:
    //credit to VAIBHAV_SHORAN, Recursive + Memoization, TC O(n), SC O(n)
    int checkRecord(int n) {
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>> (2, vector<int>(3, -1)));
        return findSol(n, 1, 2, memo);
    }
private:
    int MOD = 1e9 + 7;
    int findSol(int n, int absent, int late, vector<vector<vector<int>>> &memo){
        if(n == 0){//base case
            return 1;
        }

        if(memo[n][absent][late] != -1){
            return memo[n][absent][late];
        }

        int A, L, P;
        A = L = P = 0;

        if(absent > 0){
            A = (findSol(n - 1, absent - 1, 2, memo)) % MOD;
            
        }

        if(late > 0){
            L = (findSol(n - 1, absent, late - 1, memo)) % MOD;
            
        }

        P = (findSol(n - 1, absent, 2, memo)) % MOD;

        return memo[n][absent][late] = ((A + L) % MOD + P) % MOD;
    }
};


class Solution {
public:
    //credit to VAIBHAV_SHORAN, recursive, TLE, TC O(3^n), SC O(n)
    int checkRecord(int n) {
        return findSol(n, 1, 2);
    }
private:
    int MOD = 1e9 + 7;
    int findSol(int n, int absent, int late){
        if(n == 0){//base case
            return 1;
        }

        int A, L, P;
        A = L = P = 0;

        if(absent > 0){
            A = (findSol(n - 1, absent - 1, 2)) % MOD;
        }

        if(late > 0){
            L = (findSol(n - 1, absent, late - 1)) % MOD;
        }

        P = (findSol(n - 1, absent, 2)) % MOD;

        return (A + L + P) % MOD;
    }
};