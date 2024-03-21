class Solution {
public:
    int solve(vector<int>& n1, vector<int>& n2, int i, bool swapped,int p1,int p2, vector<vector<int>> &dp){
        if(i == n1.size()) return 0;
        int ans = INT_MAX;
        if(dp[i][swapped] != -1) return dp[i][swapped];
        if(swapped) swap(p1,p2);
        if(n1[i] > p1 && n2[i] > p2) ans = solve(n1,n2,i+1,0,n1[i],n2[i],dp);
        if(n1[i] > p2 && n2[i]>p1)  ans = min(ans, 1+ solve(n1,n2,i+1,1,n1[i],n2[i],dp));
        return dp[i][swapped] = ans;
        
    }
    int solveTab(vector<int>& n1, vector<int>& n2){
        int n = n1.size();
        // vector<vector<int>> dp(n+1,vector<int> (2,0));
        // vector<int> curr(2,0);
        // vector<int> next (2,0);
        int sp = 0, nsp =0;
        int crswp =0,crnswp =0;
        for(int i = n-1;i>=1;i--){
            for(int swp = 1;swp>=0;swp--){
                int ans = INT_MAX;
                int p1 = n1[i-1];
                int p2 = n2[i-1];
                if(swp) swap(p1,p2);
                if(n1[i] > p1 && n2[i] > p2) ans = nsp;
                if(n1[i] > p2 && n2[i]>p1)  ans = min(ans, 1+ sp);
                if(swp)
                    crswp = ans;
                else crnswp = ans;
                }
            sp = crswp;
            nsp = crnswp;
        }
        return crnswp;
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(), -1);
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        int ans =0;
        return solveTab(nums1,nums2);
    }
};