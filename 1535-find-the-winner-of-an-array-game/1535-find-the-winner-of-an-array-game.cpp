class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>=arr.size()){
            return *max_element(arr.begin(),arr.end());
        }
        int val =arr[0],cnt=0;
        int n = arr.size();
        for(int i=0;i<n;i=(i+1)%n){
            if(arr[i]<arr[(i+1)%n]){
                cnt=1;
                val = arr[(i+1)%n];
            }
            
            else{
                cnt++;
                swap(arr[i],arr[(i+1)%n]);
            }
            if(cnt==k){
                    return val; 
                }
        }
        return -1;
    }
};