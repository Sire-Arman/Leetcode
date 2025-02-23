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
TreeNode* build( vector<int>& pre, vector<int>&post,int& ind, int l, int h){
    if(ind >= pre.size() || l>h) return nullptr;
    TreeNode* root = new TreeNode(pre[ind++]);
    if(l==h) return root;
    int i = l;
    while(i<=h && post[i] != pre[ind]) i++;
    if(i<=h){
        root->left = build(pre,post,ind,l,i);
        root->right = build(pre,post,ind,i+1,h-1);
    }
    return root;

}
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
       int ind =0;
       return build(pre,post,ind,0,pre.size()-1);
        // return root;
    }
};