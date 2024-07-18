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
    vector<TreeNode*> ans;
    void dfs(TreeNode* root, bool isroot, unordered_set<int>& to_del){
        if(root == NULL) return;
        if(to_del.find(root->val) != to_del.end()){
            dfs(root->left, true, to_del);
            dfs(root->right, true, to_del);
        }
        else{
            if(isroot) ans.push_back(root);
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            if(root->left && to_del.find(root->left->val) != to_del.end()){
                root->left = NULL;
            }
            if(root->right && to_del.find(root->right->val) != to_del.end()){
                root->right = NULL;
            }
            dfs(l,false,to_del);
            dfs(r,false,to_del);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        ans.clear();
        unordered_set<int> st;
        for(auto it : to_delete){
            st.insert(it);
        }
        dfs(root,true,st);
        return ans;
    }
};