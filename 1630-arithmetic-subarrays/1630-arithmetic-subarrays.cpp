class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int> nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        vector<bool> ans;
        int q = l.size();
        for(int i=0;i<q;i++){
            int st = l[i];
            int end = r[i];
            vector<int> temp;
            for(int k=st;k<=end;k++){
                temp.push_back(nums[k]);
            }
            sort(temp.begin(),temp.end());
            int diff = temp[1]-temp[0];
            int j;
            for(j=0;j<temp.size()-1;j++){
                if(temp[j]+diff != temp[j+1]){
                    ans.push_back(false);
                    break;
                }
            }
            if(j==(temp.size()-1)) ans.push_back(true);
        }
        return ans;
    }
};