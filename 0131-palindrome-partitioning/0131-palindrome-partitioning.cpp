class Solution {
public:
    bool isdrome(string s,int i,int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void helper(string s, int ind, vector<vector<string>> &ans, vector<string> &path){
        if(ind == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i= ind;i<s.size();i++){
            if(isdrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                helper(s,i+1,ans,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
           
        vector<vector<string>> res;
        vector<string> path;
        helper(s,0,res,path);
        return res;
    }
};