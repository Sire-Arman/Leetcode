class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& tar) {
        int n = nums.size();
        int t = tar.size();
        vector<int> dif (n,0);
        for(int i=0;i<n;i++){
            dif[i] = nums[i]-tar[i];
        }
        int l=0,r=0;
        int m = 0;
        long long ans =0;
        while(r<n){
            if(dif[r] == 0 || (dif[l]>0 && dif[r]<0) || (dif[l]<0 && dif[r]>0)){
                ans += m;
                // cout<<m<<' ';
                m=0;
                l=r;
                // cout<<l<<' ';
            }
            if(dif[r] != 0){
                if(dif[l] == 0){
                    l = r;
                }
                m = max(m,abs(dif[r]));
            }
            r++;
        }
        ans += m;
        // cout<<endl;
        // return ans;
          // int n = nums.size();
        vector<long long> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = static_cast<long long>(tar[i]) - nums[i];
        }
        
        long long ans_opr = 0;
        long long curr = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i > 0 && ((diff[i-1] > 0 && diff[i] > 0) || 
                          (diff[i-1] < 0 && diff[i] < 0))) {
                long long extra = abs(diff[i]) - abs(curr);
                if (extra > 0) {
                    ans_opr += extra;
                }
                curr = diff[i];
            } else {
                ans_opr += abs(diff[i]);
                curr = diff[i];
            }
        }
        
        return ans_opr;
    }
};