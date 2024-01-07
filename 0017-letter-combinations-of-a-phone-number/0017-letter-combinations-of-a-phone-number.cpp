class Solution {
public:
    void backtrack(int ind, string temp, string d, vector<string> &ans, map<int,string> mp){
        if(ind == d.size()){
            if(temp != "") ans.push_back(temp);
            return;
        }
        string a = mp[d[ind]-'0'];
        for(int i=0;i<a.size();i++){
            temp.push_back(a[i]);
            backtrack(ind+1,temp,d,ans,mp);
            temp.pop_back();
        }
       
    }
    vector<string> letterCombinations(string d) {
        map<int,string> mp;
            mp[2] = "abc";
            mp[3] = "def";
            mp[4] = "ghi";
            mp[5] = "jkl";
            mp[6] = "mno";
            mp[7] = "pqrs";
            mp[8] = "tuv";
            mp[9] = "wxyz";
        vector<string> ans;
        string temp = "";
        backtrack(0,temp,d,ans,mp);
        return ans;
        
    }
};