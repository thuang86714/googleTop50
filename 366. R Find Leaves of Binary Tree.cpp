struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        getHeight(root);
        return res;
    }
private:
    vector<vector<int>> res;
    int getHeight(TreeNode *node){
        if(!node){
            return 0;
        }

        int height = max(getHeight(node->left), getHeight(node->right)) + 1;

        if(height > res.size()){
            res.push_back({});
        }
        res[height - 1].push_back(node->val);
        
        return height;
    }
};