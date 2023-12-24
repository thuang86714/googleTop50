#include <string>
#include <numeric>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        list<string> remWord{words.begin(), words.end()};
        auto addProb = [&](string &w, int d = 1){
            for(auto i = 0; i < 6; i++){
                prob[i][w[i] - 'a'] += d;
            }
        };
        for_each(begin(words), end(words), addProb);

        while(res < 6){
            string candidate = bestCandidate(remWord);
            res = master.guess(candidate);
            for(auto it = remWord.begin(); it != remWord.end();){
                if(match(*it, candidate) != res){
                    addProb(*it, -1);
                    remWord.erase(it++);
                }else{
                    it++;
                }
            }
        }
    }
private:
    int res = 0, prob[6][26] = {};
    string bestCandidate(list<string> words){
        string best;
        long int maxScore = 0;
        for(string w:words){
            long int score = 0;
            for(int i = 0; i < w.size(); i++){
                score += prob[i][w[i] - 'a'];
            }
            if(score > maxScore){
                best = w;
                maxScore = score;
            }
        }
        return best;
    }
    int match(const string &A, const string &B){
        int counter = 0;
        for(int i = 0; i < A.size(); i++){
            if(A[i] == B[i]){
                counter++;
            }
        }
        return counter;
    }
};