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
    bool check(TreeNode* root1,TreeNode* root2){
        if(root1 == NULL || root2 == NULL){
            if(root1 == NULL && root2 == NULL)
            return true;
            
            return false;
        }
        if(root1->val == root2->val && check(root1->left,root2->right) && check(root1->right,root2->left)){
            return true;
        }
        else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
          if(root->left == NULL && root->right == NULL){
            return true;
        }
        return check(root->left, root->right);
    }
};