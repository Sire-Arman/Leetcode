/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
TreeNode* solve(TreeNode* root, TreeNode* a, TreeNode* b){
    if(root == NULL) return NULL;
    if(root->val == a->val || root->val == b->val) return root;
    TreeNode* left = solve(root->left,a,b);
    TreeNode* right = solve(root->right,a,b);
    if(left != NULL && right != NULL) return root;
    if(left != NULL) return left;
    return right;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};