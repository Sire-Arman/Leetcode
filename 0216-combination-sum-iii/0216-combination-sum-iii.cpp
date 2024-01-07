class Solution {
public:
    void backtrack(int k, int n, vector<int> temp, vector<vector<int>>& ans, int ind){
        if(n<0) return;
        
        if(k == 0){
            if(n==0){
                ans.push_back(temp);
            }
            return;
        }
        for(int i=ind;i<10;i++){
            temp.push_back(i);
        backtrack(k-1,n-i,temp,ans,i+1);  
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<vector<int>> ans;
        vector<int> temp;
        backtrack(k,n,temp,ans,1);
        return ans;
    }
};