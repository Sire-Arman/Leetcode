/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(Node* root,vector<int>& st){
        if(root == NULL) return;
        for(auto it : root->children){
            dfs(it,st);
            if(it != NULL) st.push_back(it->val);
        }
    }
    vector<int> postorder(Node* root) {
        if(root == NULL) return {};
        vector<int> st;
        dfs(root,st);
        // vector<int> ans;
        // while(!st.empty()){
        //     ans.push_back(st.top()->val);
        //     st.pop();
        // }
        st.push_back(root->val);
        return st;
    }
};