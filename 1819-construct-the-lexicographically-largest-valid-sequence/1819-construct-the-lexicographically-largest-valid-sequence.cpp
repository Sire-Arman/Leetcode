class Solution {
public:
    bool bt(int i, map<int,int>& mp, vector<int>& ans, int m){
        if(i == ans.size()) {
            return true;
        }
        if(ans[i]>0) return bt(i+1,mp,ans,m);
        for(int val = m;val>=1;val--){
            if(!mp[val]){
                ans[i]=val;
                mp[val]++;
                if(val == 1) {
                    if(bt(i+1,mp,ans,m)) return true;
                }
                else{
                    if(i+val<ans.size() && ans[i+val]==0){
                        ans[i+val] = val;
                        if(bt(i+1,mp,ans,m)) return true;
                        ans[i+val] =0;
                    }
                }
                        mp[val]--;
                        ans[i]=0;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        int m = (n-1)*2+1;
        vector<int> a(m,0);
        map<int,int> mp;
        bool ans = bt(0,mp,a,n);
        return a;
    }
};