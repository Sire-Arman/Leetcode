class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0,b=0,c=0;
        int i=0,j=0,ans=0;
        int n = s.size();
        while(j<n){
            if(s[j] == 'a') a++;
            else if(s[j] == 'b') b++;
            else c++;
            while(a && b && c){
                ans += n-j;
                if(s[i] == 'a') a--;
                else if(s[i] == 'b') b--;
                else c--;
                i++;
            }
            j++;
        }
        return ans;
    }
};