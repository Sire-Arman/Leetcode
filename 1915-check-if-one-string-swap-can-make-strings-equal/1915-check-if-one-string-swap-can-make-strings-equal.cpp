class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        char a = '1',b='1';
        int n = s1.size();
        bool ans = false;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]){
                if(a != '1'){
                    if(ans) return false;
                    if(s1[i] == b && s2[i]==a) ans = true;
                    else return false;
                }
                else{
                    a = s1[i];
                    b = s2[i];
                }
            }
        }
        
        return ans | a =='1';
    }
};