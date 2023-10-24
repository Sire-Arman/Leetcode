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
//     int height(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }
//             int lheight = height(root->left);
//             int rheight= height(root->right);
            
//             if(lheight > rheight){
//                 return lheight+1;
//             }
//                 return rheight+1;
//     }
    
    void printlevel(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        // int temp = INT_MIN;
        // if(i == 1){
        //     temp = max(temp,root->val);
        //     ans.push_back(temp);
        // }else{
        //  printlevel(root->left,i-1,ans);
        //     printlevel(root->right,i-1,ans);
        // }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int nodecount = q.size();
            int temp = INT_MIN;
            while(nodecount>0){
              TreeNode* t = q.front();
                q.pop();
                temp = max(t->val,temp);
                
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                        q.push(t->right);
                }
                   nodecount--; 
            }
            ans.push_back(temp);
        }
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        printlevel(root,ans);
        return ans;
    }
};