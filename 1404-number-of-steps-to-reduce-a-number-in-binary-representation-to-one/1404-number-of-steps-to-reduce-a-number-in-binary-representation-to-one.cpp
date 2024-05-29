class Solution {
public:
    int numSteps(string s) {
        int p = 0;
        int num =0,cnt=0;
        for(int i=s.size()-1;i>=1;i--){
           if(s[i]=='1'){
               int c =1;
               for(int j=i;j>=0;j--){
                  if(s[j]=='1'){
                      if(c){
                          s[j]='0';
                          c=1;
                      }
                  }
                   else{
                       if(c){
                           s[j]='1';
                           c=0;
                       }
                       else{
                           s[j]='0';
                       }
                   }
               }
               cnt+=2;
           }
            else{
                cnt++;
            }
        }
        return s[0]=='0'?cnt+1:cnt;
        
    }
};