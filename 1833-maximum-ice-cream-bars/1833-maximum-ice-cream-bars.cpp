class Solution {
public:
    vector<int> countSort(vector<int>& nums){
        int n = *max_element(nums.begin(),nums.end());
        vector<int> cntArr(n+1);
        vector<int> ans(nums.size());
        for(int i = 0;i<nums.size();i++){
            cntArr[nums[i]]++;
        }
        for(int i =0;i<n;i++) cntArr[i+1] += cntArr[i];
        for(int i = nums.size()-1;i>=0;i--){
            ans[--cntArr[nums[i]]] = nums[i];
        } 
        return ans;
    }
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> sorted = countSort(costs);
        int ans = 0,n = costs.size(),i=0;
        while(i<n && coins>=sorted[i]){
            ans++;
            coins-=sorted[i];
            i++;
        }
        return ans;
    }
};