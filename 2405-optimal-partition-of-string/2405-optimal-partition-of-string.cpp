class Solution {
public:
    int partitionString(string s) {
        vector<int> freq(26,0);
        int cnt =1;
        for(auto it : s){
            if(freq[it-'a']){
                cnt++;
                freq = vector<int> (26,0);
            }
            freq[it-'a']++;
        }
        return cnt;
        
    }
};