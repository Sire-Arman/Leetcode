class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        long long ans=0;
        int prev=0;
        for(auto it : bank){
            int cnt=0;
            for(auto i : it){
                if(i=='1') cnt++;
            }
            if(cnt && prev) ans += prev*cnt;
            if(cnt) prev = cnt;
        }
        return (int)ans;
    }
};