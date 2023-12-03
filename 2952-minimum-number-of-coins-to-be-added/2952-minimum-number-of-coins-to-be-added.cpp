class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        int cnt=0;
        int minsum =0,x=0;
        for(int i=0;i<n;i++){
            while(coins[i]>x+1){
                  x = 2*x+1;
                  cnt++;
              }
                if(x>=target) return cnt;
            
                x+= coins[i]; 
            }
        while(x<target){
            x = 2*x+1;
            cnt++;
        }
        return cnt;
    }
};