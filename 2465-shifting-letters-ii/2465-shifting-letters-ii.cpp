class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
       int n = s.size();
       vector<int> diff(n);
       for(auto &it : shifts){
        if(it[2]==1){
            diff[it[0]]++;
            if(it[1]+1<n){
                diff[it[1]+1]--;
            }
        }
        else{
            diff[it[0]]--;
            if(it[1]+1<n){
                diff[it[1]+1]++;
            }
        }
       }
       int x =0;
       for(int i=0;i<n;i++){
         x = (x+diff[i])%26;
         if(x<0) x+=26;
        char it = s[i];
        s[i] = 'a' + (it-'a' + x)%26;
       }
        return s;
    }
};