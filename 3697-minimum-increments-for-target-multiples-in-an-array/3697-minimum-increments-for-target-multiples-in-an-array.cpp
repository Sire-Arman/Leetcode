#define ll long long
class Solution {
public:
    ll lcm(ll a, ll b){
        return a/__gcd(a,b)*b;
    }
    int minimumIncrements(vector<int>& nums, vector<int>& t) {
        ll k = t.size();
        map<ll,ll> mp;
        for(ll m =1;m<(1<<k);m++){
            vector<ll> subset;
            for(int i=0;i<k;i++){
                if(m&(1<<i)){
                    subset.push_back(t[i]);
                }
            }
            ll currLCM = subset[0];
            for(int i=1;i<subset.size();i++){
                currLCM = lcm(currLCM,subset[i]);
            }
            mp[m]= currLCM;
        }
        ll fullMask = (1<<k)-1;
        vector<ll> dp((1<<k),INT_MAX);
        dp[0]=0;
        for(auto it : nums){
            vector<pair<ll,ll>> maskCost;
            for(auto &e : mp){
                ll mask = e.first;
                ll lcmVal = e.second;
                ll rem = it%lcmVal;
                ll cost = rem==0?0:(lcmVal-rem);
                maskCost.push_back({mask,cost});
            }
            vector<ll> newDp = dp;
            for(ll prev =0;prev<(1<<k);prev++){
                if(dp[prev]==INT_MAX) continue;
                for(auto &it: maskCost){
                    ll mask = it.first;
                    ll cost = it.second;
                    ll nmask = prev | mask;
                    ll ncost = cost + dp[prev];
                    if(newDp[nmask]>ncost){
                        newDp[nmask] = ncost;
                    }
                }
            }
            dp = newDp;
        }
        return dp[fullMask]==INT_MAX?-1:dp[fullMask];
    }
};