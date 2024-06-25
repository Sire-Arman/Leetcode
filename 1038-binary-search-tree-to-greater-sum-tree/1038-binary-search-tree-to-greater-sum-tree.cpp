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
    void traverse(TreeNode* root, int& curr,bool dir){
        if(root == NULL){
            return;
        }
        // if(!dir) root->val += curr;
        if(root->right){
            traverse(root->right,curr,true);
        }
        root->val+=curr;
        curr=root->val;
        if(root->left){
            traverse(root->left,curr,false); 
        }
        // if(dir) root->val += curr;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int curr =0;
        traverse(root,curr,0);
        return root;
    }
};