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
    void travel(TreeNode* root, vector<int>& arr){
        if(root == NULL){
            return;
        }
        if(root->left== NULL && root->right == NULL){
            arr.push_back(root->val);
            return;
        }
        if(root->left) travel(root->left,arr);
        if(root->right) travel(root->right,arr);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a1;
        vector<int> a2;
        travel(root1,a1);
        travel(root2,a2);
        return a1 == a2;
    }
};