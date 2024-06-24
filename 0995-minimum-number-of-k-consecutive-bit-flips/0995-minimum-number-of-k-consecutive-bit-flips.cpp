class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> flipped(n-k+1, 0);  // Track where flips are made
        int cnt=0,  flip_x=0;
        
        for (int i = 0; i < n; i++) {
            if (i>=k) 
                flip_x-= flipped[i-k];// outside of sized k window
            if ((flip_x&1)==nums[i]) {  // Need to flip this window
                if (i+k > n) 
                    return -1;  // Not enough elements to flip
    
                flipped[i] = 1;  // Mark the flip
                flip_x++;  // flip 
                cnt++;
            }
        }
        return cnt;
//         for(int i=0;i<nums.size()-k+1;i++){
//             if(nums[i]==0){
//                 flip++;
//                 // sum++;
//                 for(int j=0;j<k;j++){
//                     nums[i+j] = !nums[i+j];
//                     if(nums[i+j]) sum++;
//                     else sum--;
                    
//                 }
//             }
//         }
//         if(sum != nums.size()) return -1;
//         return flip;
        
    }
};