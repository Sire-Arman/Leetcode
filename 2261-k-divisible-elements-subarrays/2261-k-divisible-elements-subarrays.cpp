class Solution {
public:
    vector<int> slicing(vector<int>& arr,
                    int X, int Y)
        {

            // Starting and Ending iterators
            auto start = arr.begin() + X;
            auto end = arr.begin() + Y + 1;

            // To store the sliced vector
            vector<int> result(Y - X + 1);

            // Copy vector using copy function()
            copy(start, end, result.begin());

            // Return the final sliced vector
            return result;
        }
    int countDistinct(vector<int>& nums, int k, int p) {
        map<int,int> mp;
        mp[0] = nums[0]%p == 0?1:0;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]%p ==0){
                mp[i] = mp[i-1]+1;
            }
            else{
                mp[i] = mp[i-1];
            }
        }
        set<vector<int>> st;
        int cnt =0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int a = i>0?mp[i-1]:0;
                if(mp[j]-a <= k) st.insert(slicing(nums,i,j));
            }
        }
        return st.size();
    }
};