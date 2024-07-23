class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int one =0,curr=0;
        int ans =0;
        for(int i=0;i<n;i++){
            if(s[i] == '0' && curr){
                ans += one;
                curr =0;
            }
            else if (s[i] == '1'){
                curr++;
                one++;
            }
        }
        return ans;
    }
};