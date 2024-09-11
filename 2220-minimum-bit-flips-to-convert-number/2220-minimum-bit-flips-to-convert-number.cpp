class Solution {
public:
    int minBitFlips(int s, int g) {
        string st = "",go="";
        while(s){
            if(s%2) st+='1';
            else st +='0';
            s/=2;
        }
        while(g){
            if(g%2) go+='1';
            else go +='0';
            g/=2;
        }
        reverse(st.begin(),st.end());
        reverse(go.begin(),go.end());
        int n = st.size();
        int m = go.size();
        int cnt =0;
        while(n && m){
            if(st[n-1] != go[m-1]){
                cnt++;
            }
            n--;
            m--;
        }
        while(n){
            if(st[n-1] == '1') cnt++;
            n--;
        }
        while(m){
            if(go[m-1]=='1') cnt++;
            m--;
        }
        return cnt;
    }
};