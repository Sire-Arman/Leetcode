class Solution {
public:
    void setbit(int num, map<int,int>& mp){
        if(num == 1 || num ==0){
            mp[num] = num;
            return;
        } 
        int cnt =0;
        int temp = num;
        while(num){
            if(num%2)cnt++;
            num/=2;
        }
        mp[temp] = cnt;
    }
    bool canSortArray(vector<int>& nums) {
        vector<int> temp = nums;
        map<int,int> mp;
        
        for(auto it : nums){
            setbit(it,mp);
            cout<<mp[it]<<' ';
        }
        for(int i=0;i<nums.size()-1;i++){
            for(int j=0;j<nums.size()-i-1;j++){
                if(nums[j]>nums[j+1] && (mp[nums[j]] == mp[nums[j+1]])){
                    swap(nums[j+1],nums[j]);
                }
                else if(nums[j]>nums[j+1] && (mp[nums[j]] != mp[nums[j+1]])) return false;
            }
        }
        return true;
    }
};