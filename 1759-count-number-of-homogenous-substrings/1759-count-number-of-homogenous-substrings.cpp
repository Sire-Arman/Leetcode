class Solution {
public:
    int countHomogenous(string s) {
        int left =0;
        int sum =0;
        for(int i=0;i<s.size();i++){
            if(s[left] == s[i]){
                sum = (sum + i-left+1)%1000000007;
            }
            else{
                sum+=1;
                left = i;
            }
        }
        return sum;
    }
};