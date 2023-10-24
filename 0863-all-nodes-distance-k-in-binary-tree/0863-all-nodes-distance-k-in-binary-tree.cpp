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
    unordered_map<TreeNode*,TreeNode*> mp;
    void parent(TreeNode* curr, TreeNode* par){
        if(!curr){
            return;
        }
        if(!par){
//             root
            par = curr;
        }
        mp[curr] = par;
        parent(curr->left,curr);
        parent(curr->right,curr);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<int,bool> visited;
        parent(root,NULL);
        queue<TreeNode*>q;
        q.push(target);
        while(k-- && !q.empty()){
            int size = q.size();
            while(size--){
               TreeNode* temp = q.front();
                visited[temp->val] = true;
                q.pop();
                if(temp->left && !visited[temp->left->val]){
                    q.push(temp->left);
                }
                if(temp->right && !visited[temp->right->val]){
                    q.push(temp->right);
                }
                if(mp[temp] && !visited[mp[temp]->val]){
                    q.push(mp[temp]);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};