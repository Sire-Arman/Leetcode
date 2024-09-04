class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans ="";
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string f=strs[0],end = strs[n-1];
        for(int i =0;i<min(f.size(),end.size());i++){
            if(f[i] != end[i]){
                return ans;
            }
            ans+=f[i];
        }
        return ans;
    }
};