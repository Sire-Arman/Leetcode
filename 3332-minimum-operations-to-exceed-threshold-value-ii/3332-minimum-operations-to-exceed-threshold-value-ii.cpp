#define ll long long 
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(auto it : nums){
            pq.push(it);
        }
        int cnt =0;
        while(!pq.empty() && pq.top() < k){
            ll a = pq.top();
            pq.pop();
            ll b = -1;
            if(pq.size()){
                b = pq.top();
                pq.pop();
            }
            if(b != -1){
                ll k = 2* min(a,b);
                pq.push(k + max(a,b));
                cnt++;
            }
        }
       return cnt; 
    }
};