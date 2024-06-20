class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int l = 1, r= pos.back()-pos[0];
        int ans =-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int last = pos[0],balls = 1;
            for(int i=0;i<pos.size();i++){
                if(pos[i]-last >= mid){
                    last = pos[i];
                    balls++;
                }
            }
            if(balls >= m){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};