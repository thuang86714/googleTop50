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
        string startPath = "", destPath = "";
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        while(!startPath.empty() && !destPath.empty() && startPath.back() == destPath.back()){
            startPath.pop_back();
            destPath.pop_back();
        }
        return string(startPath.size(), 'U') + string(destPath.rbegin(), destPath.rend());
    }
private:
    string startPath = "", endPath = "";
    bool findPath(TreeNode *node, const int curVal, string &path){
        if(node->val == curVal){
            return true;
        }

        if(node->left && findPath(node->left, curVal, path)){
            path.push_back('L');
        }else if(node->right && findPath(node->right, curVal, path)){
            path.push_back('R');
        }

        return !path.empty();
    }
};