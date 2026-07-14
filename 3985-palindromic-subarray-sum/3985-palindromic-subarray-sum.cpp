class Solution {
public:
    vector<int> manacherAlgo(vector<int>& nums){
        int n = nums.size();
        int c =0,r=0;
        vector<int> radii(n);
        for(int center=0;center<n;center++){
            if(center<r){
                int mirror = 2*c-center;
                radii[center] = min(r-center,radii[mirror]);
            }
            while(center+radii[center]+1<n && 
                center - radii[center]-1>=0 && 
                nums[center+radii[center]+1] == 
                nums[center-radii[center]-1]) radii[center]++;
            
            if(center+radii[center] > r){
                r = center+radii[center];
                c = center;
            }
        }
        return radii;
    }
    long long getSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums2;
        for(auto it : nums){nums2.push_back(it);nums2.push_back(0);};
        long long maxi = 0;
        int n2 = nums2.size();
        vector<long long> prefix(n+1,0),prefix2(n2+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i]+nums[i];
        }
        for(int i=0;i<n2;i++){
            prefix2[i+1] = prefix2[i]+nums2[i];
        }
        vector<int> res = manacherAlgo(nums);
        vector<int> res2 = manacherAlgo(nums2);
        for(int i=0;i<n;i++){
            if(res[i]){
                long long l = prefix[i-res[i]];
                long long r = prefix[i+res[i]+1] - l;
                maxi = max(maxi,r);
            }
            maxi = max(maxi,1LL*nums[i]);
        }
        for(int i=0;i<n2;i++){
            if(res2[i]){
                long long l = prefix2[i-res2[i]];
                long long r = prefix2[i+res2[i]+1] - l;
                maxi = max(maxi,r);
            }
            maxi = max(maxi,1LL*nums2[i]);
        }
        return maxi;

    }
};