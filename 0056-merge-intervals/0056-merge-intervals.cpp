class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
         vector<vector<int>> ans;
        sort(inter.begin(),inter.end());
        int n = inter.size(),index=-1;
        for(int i=0;i<n;i++){
            if(ans.empty()){
                ans.push_back(inter[i]);
                index++;
            }
            else if(inter[i][0] <= ans[index][1]){
                ans[index][1] = max(inter[i][1],ans[index][1]);
            }
            else{
                ans.push_back(inter[i]);
                index++;
            }
        }
        return ans;
    }
};