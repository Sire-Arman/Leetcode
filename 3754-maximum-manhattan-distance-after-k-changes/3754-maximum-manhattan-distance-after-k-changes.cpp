class Solution {
public:
    int maxDistance(string s, int k) {
        int n=0,e=0;
        int ans =1;
        for(int i=0;i<s.size();i++){
            switch(s[i]){
                case 'N': n++;break;
                case 'S': n--;break;
                case 'E': e++;break;
                case 'W': e--;break;
            }
            ans = max(ans,min(abs(n)+abs(e)+2*k,i+1));
        }
        return ans;
    }
};