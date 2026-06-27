class Solution {
public:
    long long isPerfectSquare(long long n) {
        if (n < 1) return -1;
        long long sq = (long long)sqrt((double)n);
        for (long long s = max(1LL, sq - 1); s <= sq + 1; s++) {
            if (s * s == n) return s;
        }
        return -1;
    }

    int maximumLength(vector<int>& nums) {
        map<int,int> mp;
        sort(nums.rbegin(),nums.rend());
        for(auto it : nums) mp[it]++;
        int ans = 0,curr=0;
        for(int i = 0;i<nums.size();i++){
            if(!mp[nums[i]]) continue;
            curr=1;
            int sq = isPerfectSquare(nums[i]);
            // cout<<sq<<' '<<nums[i]<<endl;
            mp[nums[i]]--;
            while(sq != -1){
                if(mp[sq]>=2){
                    curr+=2;
                    mp[sq]-=2;
                }
                else{
                    break;
                }
                sq = isPerfectSquare(sq);
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};