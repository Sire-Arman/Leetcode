class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=0;
        int ans =0,v=0;
        int s = arr.size();
        bool prev = false;
        for(int i=0;i<arr.size();i++){
           n+=i;
            v+=arr[i];
            if(v == n) ans++;
        }
        return ans;
        
    }
};