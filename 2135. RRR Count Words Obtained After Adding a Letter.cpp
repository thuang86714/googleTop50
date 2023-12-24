class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> dict;
        for(string word:startWords){
            string temp = word;
            sort(temp.begin(), temp.end());
            dict.insert(temp);
        }
        int ans = 0;
        for(string &target:targetWords){
            sort(target.begin(), target.end());
            for(int i = 0; i < target.size(); i++){
                string temp = target.substr(0, i) + target.substr(i + 1);
                if(dict.count(temp)){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};