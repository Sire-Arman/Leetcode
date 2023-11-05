class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>=arr.size()){
            return *max_element(arr.begin(),arr.end());
        }
        int val =arr[0],cnt=0;
        int n = arr.size();
        for(int i=1;i<n;i++){
            if(val<arr[i]){
                cnt=1;
                val = arr[i];
            }
            if(cnt==k){
                    return val; 
                }
            else{
                cnt++;
            }
        }
        return val;
    }
};