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
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL) return true;
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int val = flag? INT_MIN : INT_MAX;
            int s = q.size();
            for(int i=0;i<s;i++){
                auto temp = q.front();
                q.pop();
                if(flag){
                        if(temp->val%2 == 0 || temp->val <= val ){
                            return false;
                        }
                    }
                    else{
                          if(temp->val%2 != 0 || temp->val >= val ){
                            return false;
                        }  
                    }
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                    val = temp->val;
                }
            flag = !flag;
            }
            
        return true;
    }
};