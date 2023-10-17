class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
       unordered_map<int,vector<int>> graph;
        vector<int> in_deg (n,0);
        
        for(int i = 0;i<n;i++){
            int left = leftChild[i];
            int right = rightChild[i];
            
            if(left != -1){
                graph[i].push_back(left);
                in_deg[left]++;
            }
            if(right != -1){
                graph[i].push_back(right);
                in_deg[right]++;
            }
        }
        vector<int> root_cand;
        for(int i=0;i<n;i++){
            if(in_deg[i] == 0)
            root_cand.push_back(i);
        }
        if(root_cand.size() != 1){
                return false;
            }
        int root = root_cand[0];
        queue<int> q;
        unordered_set<int> seen;
        q.push(root);
        seen.insert(root);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(graph.find(node) != graph.end()){
                for(int child : graph[node]){
                    if(seen.find(child) != seen.end()){
                        return false;
                    }
                    seen.insert(child);
                    q.push(child);
                }
            }
            
        }
        return seen.size() == n;
    }
};