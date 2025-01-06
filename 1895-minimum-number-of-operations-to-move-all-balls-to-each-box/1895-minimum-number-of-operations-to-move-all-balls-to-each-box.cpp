class Solution {
public:
    vector<int> minOperations(string b) {
        vector<int> ans(b.size());
        vector<int> pref (b.size()+1);
        int total =0,sum=0;
        for(int i=b.size()-1;i>=0;i--){
            if(b[i]=='1'){
                total++;
                sum += i;
            }
            pref[i] = total;
        }
        ans[0] = sum;
        for(int i=1;i<b.size();i++){
            int f = pref[i];
            int b = total-pref[i];
            sum = sum - f + b;
            ans[i] = abs(sum);
        }
        return ans;
    }
};