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
int idx =0,level=0;
string s;
    int countDash(string& t, int& i){
        if(i>=t.size() || t[i] != '-') return 0;
        return 1+countDash(t,++i);
    }
    int findNum(string& t, int& i){
        int ans = 0;
        while(i<t.size() && t[i] !='-') {
            ans = ans*10+(t[i]-'0');
            i++;
        }
        return ans;
    }
     void helper(TreeNode* parent, int lvl) {
        while (idx < s.length() && lvl == level) {
            int num = 0;
            while (idx < s.length() && isdigit(s[idx])) {
                num = num * 10 + (s[idx++] - '0');
            }
            TreeNode* node = new TreeNode(num);
            if (!parent->left)
                parent->left = node;
            else
                parent->right = node;
            level = 0;
            while (idx < s.length() && s[idx] == '-') {
                level++;
                idx++;
            }
            helper(node, lvl + 1);
        }
    }
    TreeNode* recoverFromPreorder(string t) {
        unordered_map<int,vector<int>> mp;
        TreeNode* ans = new TreeNode(-1);
        s= t;
        helper(ans,0);
        return ans->left;
       
    }
};