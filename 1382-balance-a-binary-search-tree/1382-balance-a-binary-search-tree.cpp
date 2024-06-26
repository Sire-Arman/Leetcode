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
    
    void traverse(TreeNode* root,vector<int>& ans){
        if(root == NULL){
            return;
        }
        if(root->left) traverse(root->left,ans);
        ans.push_back(root->val);
        if(root->right) traverse(root->right,ans);
    }
    TreeNode* build(int st,int end, vector<int>& ans){
        if(st>end) return nullptr;
        int mid = (st + end)/2;
        TreeNode* nptr = new TreeNode(ans[mid]);
        nptr->left = build(st,mid-1,ans);
        nptr->right = build(mid+1,end,ans);
        return nptr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        traverse(root,ans);
        return build(0,ans.size()-1,ans);
    }
};