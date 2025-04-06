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
int maxD = -1;
void maxDepth(TreeNode* root, int d){
if(root == NULL) return;
 if(root->left == NULL && root->right == NULL){
        maxD = max(maxD,d);
        return;
    }
    maxDepth(root->left,d+1);
    maxDepth(root->right,d+1);
}
void dfs(TreeNode* root, int d, unordered_set<int>& st){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        if(d == maxD) st.insert(root->val);
        return;
    }
    dfs(root->left,d+1,st);
    dfs(root->right,d+1,st);
}
TreeNode* solve(TreeNode* root, unordered_set<int>& st){
    if(root == NULL) return NULL;
    if(st.find(root->val) != st.end()) return root;
    TreeNode* left = solve(root->left,st);
    TreeNode* right = solve(root->right,st);
    if(left != NULL && right != NULL) return root;
    if(left != NULL) return left;
    return right;
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_set<int> st;
        maxDepth(root,0);
        dfs(root,0,st);
        return solve(root,st);

    }
};