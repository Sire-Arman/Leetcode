class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        int cnt =0;
        int maxi = INT_MIN;
        string temp ="";
        string large  ="";
        for(int i=0;i<n;i++){
            int j=i+1,k=j+1;
            if(k<num.size() && num[i]==num[k] && num[j]==num[k]){
               temp +=num[i];
                temp+= num[j];
                temp+=num[k];
                large = max(large,temp);
                temp = "";
            }
        }
        return large;
    }
};