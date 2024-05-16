/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void bfs(Node* root){
        if(root == NULL) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<Node*> temp;
            while(!q.empty()){
                Node* x = q.front();
                q.pop();
                if(x->left){
                    temp.push_back(x->left);
                    temp.push_back(x->right);
                }
                if(q.empty()) x->next = NULL;
                else x->next = q.front();
            }
            for(auto it : temp){
                q.push(it);
            } 
        }
    }
    Node* connect(Node* root) {
        bfs(root);
        return root;
    }
};