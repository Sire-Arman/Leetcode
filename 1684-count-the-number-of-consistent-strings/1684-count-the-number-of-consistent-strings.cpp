class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> all(26,0);
        for(auto it : allowed){
            all[it-'a']=1;
        }
        int cnt = words.size();
        for(auto it : words){
            for(auto i : it) if(all[i-'a'] == 0) {cnt--;break;}
        }
        return cnt;
    }
};