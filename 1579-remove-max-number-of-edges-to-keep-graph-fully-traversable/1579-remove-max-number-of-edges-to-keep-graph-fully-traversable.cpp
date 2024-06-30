class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    int comp;
    DSU(int nodes){
        parent.resize(nodes+1);
        size.resize(nodes+1,1);
        iota(parent.begin(),parent.end(),0);
        comp = nodes;
    }
    int findParent(int node){
        if(node == parent[node]) return node;
        parent[node] = findParent(parent[node]);
        return parent[node];
    }
    int unionBysize(int n1, int n2){
        int r1 = findParent(n1);
        int r2 = findParent(n2);
        if(r1 == r2){
            return 0;
        }
        comp--;
        if(size[r1] < size[r2]){
            parent[r1] = r2;
            size[r2]+= size[r1];
        }
        else{
            parent[r2] = r1;
            size[r1]+=size[r2];
        }
        return 1;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int reqEdge = 0;
        DSU alice(n);
        DSU bob(n);
        sort(edges.begin(),edges.end(),greater<vector<int>>());
        for(auto it : edges){
            if(it[0] == 3){
                reqEdge += alice.unionBysize(it[1],it[2]);
                bob.unionBysize(it[1],it[2]);
            }
            else if (it[0] == 2){
                reqEdge += alice.unionBysize(it[1],it[2]);
            }
            else{
                reqEdge += bob.unionBysize(it[1],it[2]);
            }
        }
        return (alice.comp>1||bob.comp>1)?-1:edges.size()-reqEdge;
    }
};