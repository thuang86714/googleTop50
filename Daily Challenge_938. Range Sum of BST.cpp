struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        findRange(root, low, high);
        return ans;
    }
private:
    void findRange(TreeNode* root, int low, int high){
        if(!root){
            return;
        }

        if(low <= root->val && high >= root->val){
            ans += root->val;
        }
        findRange(root->left, low, high);
        findRange(root->right, low, high);
    }
    int ans = 0;
};