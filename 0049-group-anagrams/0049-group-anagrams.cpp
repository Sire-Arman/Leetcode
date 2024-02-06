class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<int,string> mp;
        for(int i=0;i<n;i++){
            mp[i] = strs[i];
        }
        for(auto &it : strs){
            sort(it.begin(),it.end());
        }
        map<string,int> mq;
        vector<vector<string>> ans;
        int k=1;
            vector<string> temp;
        for(int i=0;i<n;i++){
            if(!mq[strs[i]]){
                mq[strs[i]] = k;
                ans.push_back({});
                ans[k-1].push_back(mp[i]);
                k++;
            }
            else{
                ans[mq[strs[i]]-1].push_back(mp[i]);
            }
           
        }
        return ans;
    }
};