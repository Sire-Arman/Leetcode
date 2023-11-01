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
    void solve( map<int,int> &mp, TreeNode* root){
        if(root == NULL){
            return;
        }
        mp[root->val]++;
        solve(mp,root->left);
        solve(mp,root->right);
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        solve(mp,root);
        if(mp.empty()){
            return ans;
        }
        int maxi = INT_MIN;
        for(auto it : mp){
            maxi = max(it.second,maxi);
        }
        for(auto it : mp){
            if(it.second == maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
        
    }
};