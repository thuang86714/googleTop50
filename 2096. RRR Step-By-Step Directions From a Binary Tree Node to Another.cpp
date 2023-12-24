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
    bool findPath(TreeNode *node, int value, string &path){
        if(node->val == value){
            return true;
        }

        if(node->left && findPath(node->left, value, path)){
            path.push_back('L');
        }else if(node->right && findPath(node->right, value, path)){
            path.push_back('R');
        }

        return !path.empty();
    }
};