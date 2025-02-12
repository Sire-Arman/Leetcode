class Solution {
public:
    int digSum(int n){
        if(n<=9) return n;
        return n%10+digSum(n/10);
    }
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        map<int,set<int,greater<int>>> mp;
        for(auto it : nums){
            int s = digSum(it);
            if(!mp[s].empty()){
                ans = max(ans,it+*mp[s].begin());
            }
            mp[s].insert(it);
        }
        return ans;
    }
};