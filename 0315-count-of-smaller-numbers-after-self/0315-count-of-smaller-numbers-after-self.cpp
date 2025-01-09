int n;
vector<int> bit;
void update(int id, int val){
    while(id<(1e4*2+1)){
        bit[id]+=val;
        id = id | (id+1);
    }
}
int query(int id){
    int ans =0;
    while(id>=0){
        ans += bit[id];
        id = (id & (id+1))-1;
    }
    return ans;
}
class Solution {
public:

    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        vector<int> ans(n);
        bit = vector<int>(1e4*2+1,0);
        for(auto it : nums){
            update(it+1e4,1);
        }
        int i=0;
        for(int it : nums){
            ans[i++] = query(it-1+1e4);
            update(it+1e4,-1);
        }
        return ans;

    }
};