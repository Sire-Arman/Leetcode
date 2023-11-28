class Solution {
public:
    int numberOfWays(string c) {
        int cnt=0;
        long long res =1;
        for (int i=0;i<c.size();i++){
            if(c[i] == 'S'){
                cnt++;
                while(++i<c.size() && c[i] != 'S');
                if(i<c.size()){
                    cnt++;
                }
                int div =1;
                while(++i<c.size() && c[i]!='S'){
                    div++;
                }
                if(div>1 && i<c.size()){
                    res = (res*div)%1000000007;
                }
                i--;
            }
            
        }
        if(cnt == 0 || cnt %2 !=0){
            return 0;
        }
        return (int)res;
    }
};