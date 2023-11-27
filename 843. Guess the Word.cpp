/*
You are given an array of unique strings words where words[i] is six letters long. One word of words was chosen as a secret word.

You are also given the helper object Master. You may call Master.guess(word) where word is a six-letter-long string, and it must be from words. Master.guess(word) returns:

-1 if word is not from words, or
an integer representing the number of exact matches (value and position) of your guess to the secret word.
There is a parameter allowedGuesses for each test case where allowedGuesses is the maximum number of times you can call Master.guess(word).

For each test case, you should call Master.guess with the secret word without exceeding the maximum number of allowed guesses. You will get:

"Either you took too many guesses, or you did not find the secret word." if you called Master.guess more than allowedGuesses times or if you did not call Master.guess with the secret word, or
"You guessed the secret word correctly." if you called Master.guess with the secret word with the number of calls to Master.guess less than or equal to allowedGuesses.
The test cases are generated such that you can guess the secret word with a reasonable strategy (other than using the bruteforce method).

 

Example 1:

Input: secret = "acckzz", words = ["acckzz","ccbazz","eiowzz","abcczz"], allowedGuesses = 10
Output: You guessed the secret word correctly.
Explanation:
master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6 matches.
master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
master.guess("abcczz") returns 4, because "abcczz" has 4 matches.
We made 5 calls to master.guess, and one of them was the secret, so we pass the test case.
Example 2:

Input: secret = "hamada", words = ["hamada","khaled"], allowedGuesses = 10
Output: You guessed the secret word correctly.
Explanation: Since there are two words, you can guess both.
 

Constraints:

1 <= words.length <= 100
words[i].length == 6
words[i] consist of lowercase English letters.
All the strings of wordlist are unique.
secret exists in words.
10 <= allowedGuesses <= 30
*/

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
#include <string>
#include <numeric>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


class Solution {
public:
    int res = 0, probs[6][26] = {};
    int match(string &w1, string &w2) {
        return inner_product(begin(w1), end(w1), begin(w2), 0, plus<int>(), equal_to<char>());
    }
    string bestCandidate(list<string>& words) {
        string best;
        long long int max_score = 0;
        for (auto w : words) {
            long long int score = 1;
            for (auto i = 0; i < 6; ++i)
                score *= probs[i][w[i] - 'a'];
            if (score > max_score) {
                max_score = score;
                best = w;
            }
        }
        return best;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        list<string> remWords(begin(wordlist), end(wordlist));
        auto add_prob = [&](string &w, int d = 1) {
        for (auto i = 0; i < 6; ++i)
            probs[i][w[i] - 'a'] += d;
        };
        for_each(begin(wordlist), end(wordlist), add_prob);
        while (res < 6) {
            auto candidate = bestCandidate(remWords);
            res = master.guess(candidate);
            for (auto it = remWords.begin(); it != remWords.end(); ){
                if (match(*it, candidate) != res) {
                    add_prob(*it, -1);
                    remWords.erase(it++);
                }else{
                    ++it;
                }
            }   
    }
}
};