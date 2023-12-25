class Solution {
    
    int solve(string s,int i,vector<int>& save){
        if(i == s.size()){  
            return 1;
        }
        if(s[i] == '0') return 0;
        if(save[i] != -1) return save[i];
        int ways = solve(s,i+1,save);
        if(i+1<s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] <='6'))){
            ways += solve(s,i+2,save);
        }
        save[i] = ways;
        return ways;  
    }
public:
    int numDecodings(string s) {
if(s[0]== '0'){
return 0;
}
for(int i=1;i<s.size();i++){
    if(s[i]=='0' && (s[i-1]<'1' || s[i-1]>'2'))
        return 0;
}
        vector<int> save(s.size(),-1);
        return solve(s,0,save);
    }
    
};