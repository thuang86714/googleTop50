#include <utility>
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
    double maximumAverageSubtree(TreeNode* root) {
        double ans = 0;
        calAVG(root);
        return maxi;
    }
private:
    double maxi = 0;
    pair<double, int> calAVG(TreeNode *node){
        if(!node){
            return {0, 0};
        }
        auto leftP = calAVG(node->left);
        auto rightP = calAVG(node->right);
        double sum = node->val + leftP.first*leftP.second + rightP.first*rightP.second;
        int nodeNum = leftP.second + rightP.second + 1;
        if(maxi < leftP.first){
            maxi = leftP.first;
        }
        if(maxi < rightP.first){
            maxi = rightP.first;
        }
        if(maxi < (double)sum/nodeNum){
            maxi = (double)sum/nodeNum;
        }
        
        return {(double)sum/nodeNum, nodeNum};
    }
};