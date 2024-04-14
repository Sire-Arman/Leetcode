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
   bool isLeaf(TreeNode* root){
    if(root->left ==NULL && root->right==NULL){
        return true;
    }
    return false;
}
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum =0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                if(isLeaf(temp->left)){
                    sum+=temp->left->val;
                }
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            }
        }
        return sum;

    }
};