class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0,cnt=0;
        int n = arr.size();
        vector<int> prefix(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1]^arr[i-1];
            // cout<<prefix[i]<<' ';
        }
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                // if(i==0){
                //     if(prefix[j]==0) cnt++;
                // } 
                // else if(prefix[j]^prefix[i-1]==0) cnt++;
                if(prefix[i]==prefix[j]) cnt+= j-i-1;
                // int a=0;
                // for(int k=i;k<=j;k++){
                //     a^= arr[k];
                // }
                // if(a==0) cnt+= j-i;
            }
        }
        return cnt;
    }
};