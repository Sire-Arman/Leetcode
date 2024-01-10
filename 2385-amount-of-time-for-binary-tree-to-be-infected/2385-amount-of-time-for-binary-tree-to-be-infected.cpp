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
// maps nodes to their parent node
// finds target node
        
TreeNode* mapping( TreeNode* root, map <TreeNode* , TreeNode*> &parent,int target){
TreeNode* res = NULL;
queue<TreeNode*>q;
q.push(root);
parent[root] = NULL;
while(!q.empty()){
    TreeNode* front = q.front();
    q.pop();
    if(front->val == target){
        res = front;
    }
    if( front->left){
        parent[front->left] = front;
        q.push(front->left);
    }
    if( front->right){
        parent[front->right] = front;
        q.push(front->right);
    }
}
return res;
}
int burner(map <TreeNode* , TreeNode*>&parent,map <TreeNode* , bool> visited,TreeNode* target){
int time =0;
queue<TreeNode*>q;
    q.push(target);
    visited[target] = true;
while(!q.empty()){
    bool c = false;
    int size = q.size();
        for(int i =0;i<size;i++){
            TreeNode* root = q.front();
                q.pop();
            if(root->left && !visited[root->left]){
                visited[root->left]=true;
                q.push(root->left);
                c= true;
            }
            if(root->right && !visited[root->right]){
                visited[root->right]=true;
                q.push(root->right);
                c=true;
            }
            if(parent[root] && !visited[parent[root]]){
                visited[parent[root]]=true;
                q.push(parent[root]);
                c=true;
            }
        }
        if(c){
                time++;
            }
}
    return time;
}
    int amountOfTime(TreeNode* root, int start) {
        
        map <TreeNode* , TreeNode*> parent;
        map <TreeNode* , bool> visited;
        TreeNode* targ = mapping(root,parent,start);
        int time = burner(parent,visited,targ);
return time;
    }
};