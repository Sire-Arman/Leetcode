int n;
vector<int> BIT;
void update(int id, int val){
    for(;id<=n;id += id&-id){
        BIT[id]+=val;
    }
}
int query(int id){
    int res = 0;
    for(;id>0;id -= id&-id){
        res+=BIT[id];
    }
    return res;
}
class Solution {
public:
    vector<int> processQueries(vector<int>& q, int m) {
        vector<int> res,pos(m+1);
        n = 2*m;
        BIT = vector<int>(2*m+1);
        for(int i=0;i<m;i++){
            update(i+m+1,1);
            pos[i+1] = i+m+1;
        }
        int front = m;
        for(auto &it : q){
            int i = pos[it];
            int np = query(i-1);
            res.push_back(np);
            update(i,-1);
            update(front,1);
            pos[it] = front;
            front--;
        }
        return res;
    }
};