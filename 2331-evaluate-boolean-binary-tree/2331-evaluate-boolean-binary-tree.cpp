/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int traverse(TreeNode* root){
        if(root->left == NULL && root->right == NULL) return root->val;
        int a = 0,b=0;
        if(root->left) a= traverse(root->left);
        if(root->right) b = traverse(root->right);
        if(root ->val == 2) return a|b;
        else return a&b;
    }
    bool evaluateTree(TreeNode* root) {
        return traverse(root);
    }
};