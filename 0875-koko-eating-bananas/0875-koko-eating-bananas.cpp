class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int l = 0,r=*max_element(p.begin(),p.end());
        int ans = r;
        while(l+1<r){
            int mid = l + (r-l)/2;
            int t =0;
            for(auto it : p){
                t += (it/mid + (it%mid!=0));
                if(t>h) break;
            }
            if(t <= h){
                ans = mid;
                r = mid;
            } 
            else{
                l= mid;
            }
        }
        return r;
    }
};