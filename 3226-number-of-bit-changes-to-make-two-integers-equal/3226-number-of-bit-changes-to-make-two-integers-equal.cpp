class Solution {
public:
    int minChanges(int n, int k) {
        string bin_n ="";
        string bin_k ="";
        while(n){
            if(n%2) bin_n +='1';
            else bin_n += '0';
            n/=2;
        }
        reverse(bin_n.begin(),bin_n.end());
        while(k){
            if(k%2) bin_k += '1';
            else bin_k +='0';
            k/=2;
        }
        
        // for(auto it : bin_n){
        //     cout<<it<<' ';
        // }
        // cout<<endl;
        if(bin_n.size()<bin_k.size()) return -1;
        while(bin_k.size()<bin_n.size()){
            bin_k.push_back('0');
        }
        reverse(bin_k.begin(), bin_k.end());
        int cnt =0;
        for(int i=0;i<min(bin_n.size(),bin_k.size());i++){
            if(bin_n[i] == '0' && bin_n[i] != bin_k[i]){
                return -1;
            }
            else if (bin_n[i] != bin_k[i]){
                cnt++;
            }
        }
        return cnt;
    }
};