class Solution {
public:
    int numTeams(vector<int>& rating) {
       int ans=0;
        int n=rating.size();
        for(int i=1;i<n-1;i++){
            int leftsml=0;
            int rightsml=0;
            int leftlrg=0;
            int rightlrg=0;
            int k=i;
            while(k--){
                if(rating[k]<rating[i])leftsml++; //no of smaller elements on left side
                if(rating[k]>rating[i])leftlrg++; //no of larger elements on left side
            }
            k=i;
            while(++k<n){
                if(rating[k]<rating[i])rightsml++; //no of smaller elements on right side
                if(rating[k]>rating[i])rightlrg++; //no of larger elements on right side
            }

            ans+=(leftsml*rightlrg)+(leftlrg*rightsml);
        }
        return ans;
    }
};