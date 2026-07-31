class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int cnt = 0,ans=0;
        vector<int> mp(26,0);
        for(auto it: word){
            mp[it-'a']++;
        }
        sort(mp.begin(),mp.end());
        int i = 25;
        while(i>=0){
            ans += mp[i]*(cnt/8+1);
            i--;
            cnt++;
        }
        return ans;
    }
};