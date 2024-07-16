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
        
// bool find(TreeNode* n, int val, string& path) {
//         if (n->val == val)
//             return true;
//         if (n->left && find(n->left, val, path))
//             path.push_back('L');
//         else if (n->right && find(n->right, val, path))
//             path.push_back('R');
//         return !path.empty();
//     }
    bool find(TreeNode* root, int s, string &ans){
        if(root->val == s) return true;
        if(root ->left && find(root->left,s,ans)){
            ans.push_back('L');
        }
        else if(root->right && find(root->right ,s, ans)){
            ans.push_back('R');
        }
        return !ans.empty();
    }
    string getDirections(TreeNode* root, int s, int d) {
        string a ;
        string b ;
        TreeNode* temp = root;
        find(temp,s,a);
        find (root,d,b);
        while(!a.empty() && !b.empty() && a.back() == b.back()){
            a.pop_back();
            b.pop_back();
        }
        // return b;
        return string(a.size(),'U') + string(rbegin(b),rend(b));
    }
};