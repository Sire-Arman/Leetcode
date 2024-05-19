#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll b = INT_MAX, sum =0,cnt=0;
        
        for (auto it : nums){
            if((it^k) > it){
                sum += it^k;
                b = min(b, (ll)(it^k)-it);
                cnt++;
            }
            else{
                sum += it;
                b = min(b, (ll)it-(it^k));
            }
        }
        if(cnt%2==0) return sum;
        return sum-b;
    }
};