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
class FindElements {
public:
TreeNode* root;
    bool dfs(TreeNode* root, int target){
        if(root == NULL) return false;
        if(root->val == target) return true;
        bool ans = false;
        if(root->left) ans = ans | dfs(root->left,target);
        if(root->right) ans = ans | dfs(root->right, target);
        return ans;
    }
    void bfs(TreeNode* root){
        if(root==NULL) return;
        queue<TreeNode*> q;
        root->val = 0;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left != NULL){
                cur->left->val = 2*(cur->val)+1;
                q.push(cur->left);
            }
            if(cur->right != NULL){
                cur->right->val = 2*(cur->val)+2;
                q.push(cur->right);
            }
        }
    }
    FindElements(TreeNode* root) {
        this->root = root;
        bfs(this->root);
    }
    
    bool find(int target) {
        return dfs(root,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */