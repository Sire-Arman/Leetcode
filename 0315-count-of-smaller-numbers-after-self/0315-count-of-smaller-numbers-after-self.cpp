vector<int>bit;
int n;
void update(int id, int val){
    for(;id<=n;id += (id&-id)){
        bit[id] += val;
    }
}
int query(int id){
    int sum =0;
    for(;id>0;id -= (id&-id)){
        sum += bit[id];
    }
    return sum;
}
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        n = 2*1e4;
        bit = vector<int>(n+1,0);
        vector<int> ans(nums.size());
        int i=0;
        for(auto &it : nums){
            update(it+1e4+1,1);
        }
        for(auto &it:nums){
            ans[i++] = query(it+1e4);
            update(it+1e4+1,-1);
        }
        return ans;
    }
};