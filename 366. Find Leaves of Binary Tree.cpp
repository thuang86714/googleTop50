/*
Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.
 

Example 1:
Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not matter the order on which elements are returned.
Example 2:

Input: root = [1]
Output: [[1]]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        //credit to GraceMeng and sxycwzwzq, TC O(n), SC O(height of the tree)
        getHeight(root);
        
        return res;
    }
private:
    vector<vector<int>> res;
    int getHeight(TreeNode* node){
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

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        //credit to GraceMeng, TC O(n), SC O(height of the tree)
        getHeight(root);
        vector<vector<int>> res;
        for(int i = 1; i <= maxHeight; i++){
            res.push_back(heightTracker[i]);
        }

        return res;
    }
private:
    int maxHeight = 0;
    unordered_map<int, vector<int>> heightTracker;
    int getHeight(TreeNode* node){
        if(!node){
            return 0;
        }

        int height = max(getHeight(node->left), getHeight(node->right)) + 1;
        heightTracker[height].push_back(node->val);
        maxHeight = max(maxHeight, height);
        return height;
    } 
};