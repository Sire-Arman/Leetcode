class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26,0);
        int l = 0,r=0;
        int ans=0;
        while(r<s.size()){
            freq[s[r]-'a']++;
            while(l<r && freq[s[r]-'a']>2){
                freq[s[l]-'a']--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};