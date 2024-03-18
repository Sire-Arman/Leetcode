class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        for(auto it : word){
            freq[it-'a']++;
        }
        int del =0, ans = word.size();
        sort(freq.begin(),freq.end());
        for(int j =0;j<freq.size();j++){
            int res = del, minfreq = freq[j];
            for(int i = freq.size()-1;i>j;i--){
                if(freq[i] - minfreq <= k)break;
                    res += freq[i] - minfreq - k;
            }
            ans = min(res,ans);del += freq[j];
        }
        return ans;
    }
};