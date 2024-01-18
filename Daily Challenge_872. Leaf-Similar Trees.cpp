#include <vector>
using namespace std;

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1, seq2;
        findLeafSeq(root1, seq1);
        findLeafSeq(root2, seq2);
        return seq1 == seq2;
    }
private:
    void findLeafSeq(TreeNode* cur, vector<int> &seq){
        if(!cur){
            return;
        }
        if(!cur->left && !cur->right){
            seq.push_back(cur->val);
            return;
        }

        findLeafSeq(cur->left, seq);
        findLeafSeq(cur->right, seq);
    }

};