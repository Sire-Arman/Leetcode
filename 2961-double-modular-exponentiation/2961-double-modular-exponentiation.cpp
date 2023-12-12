class Solution {
public:
    int pow(int a ,int b, int n) {
        int ans=1;
        for(int i=0;i<b;i++){
            ans = (ans*a)%n;
        }
        return ans;
            
        }
    
    vector<int> getGoodIndices(vector<vector<int>>& v, int target) {

        vector<int> ans;
        for(int i=0;i<v.size();i++){
            int a = v[i][0];
            int b = v[i][1];
            int c = v[i][2];
            int m = v[i][3];
            int x = pow(a,b,10);
            int var = pow(x,c,m);
            if(var == target){
                ans.push_back(i);
            }
        }
        return  ans;
    }
};