class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int i=0,j=n-1,c=0;
        vector<int> a,b;
        while(c<n){
            if(nums[c]<pivot){
                a.push_back(nums[c]);
            }
            else if(nums[c]>pivot){
                b.push_back(nums[c]);
            }
            c++;
        }
        int e = n-a.size()-b.size();
        while(e--){
            a.push_back(pivot);
        }
        for(auto&it : b){
            a.push_back(it);
        }
        // reverse(nums.begin()+j+1,nums.end());
        // if(pivot<0) reverse(nums.begin(),nums.begin()+i);
        return a;
    }
};