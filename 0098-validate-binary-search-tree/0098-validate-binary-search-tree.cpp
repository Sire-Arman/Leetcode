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
    #define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
bool isValid(TreeNode *root, long leftBound, long rightBound, bool &res)
{
    if (!root)
        return true;
    if (root->val < rightBound && root->val > leftBound)
    {
        bool left = isValid(root->left, leftBound, root->val, res);
        if (res && left)
            bool right = isValid(root->right, root->val, rightBound, res);
        else
            res = false;
    }
    else
        res = false;
    return res; 
}

bool isValidBST(TreeNode *root)
{
    DPSolver;
    bool res = true ;
    isValid(root,  LLONG_MIN, LLONG_MAX,  res); 
    return res; 
}
 };

