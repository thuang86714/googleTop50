#include <string>
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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        //credit to votrubac, TC O(n + logn), SC O(logn), where n is total node in the tree
        string startPath, destPath;
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        while(!startPath.empty() && !destPath.empty() && startPath.back() == destPath.back()){
            startPath.pop_back();
            destPath.pop_back();
        }

        return string(startPath.size(), 'U') + string(rbegin(destPath), rend(destPath));
    }
private:
    bool findPath(TreeNode* node, int &targetVal, string &path){
        if(node->val == targetVal){
            return true;
        }

        if(node->left && findPath(node->left, targetVal, path)){
            path.push_back('L');
        }else if(node->right && findPath(node->right, targetVal, path)){
            path.push_back('R');
        }

        return !path.empty();
    }
};