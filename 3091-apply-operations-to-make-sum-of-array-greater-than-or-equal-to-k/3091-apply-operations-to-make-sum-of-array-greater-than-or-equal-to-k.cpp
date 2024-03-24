class Solution {
public:
    int solve(int n, int k){
        if(n >= k) return 0;
        int ans = INT_MAX;
        int a = ceil(k/(n*1.0));
        int x = min(1+solve(n+1,k) , a);
        ans = min(ans,x);
        return ans;
    }
    int minOperations(int k) {
        int ans = INT_MAX;
        for(int i = 1;i<= k;i++){
            int a = ceil(k/(i*1.0));
            int x = i-1+a;
            ans = min(ans, x );
        }
        return ans-1;
    }
};