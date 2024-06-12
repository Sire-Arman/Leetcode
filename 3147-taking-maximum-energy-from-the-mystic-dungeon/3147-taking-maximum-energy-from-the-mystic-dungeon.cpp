class Solution {
public:
    int maximumEnergy(vector<int>& e, int k) {
     int sum = INT_MIN;
        int n = e.size();
        for(int i=n-1;i>=0;i--){
            if(i+k < n){
                e[i] += e[i+k];
            }
        }
        for(auto it : e){
            sum = max(sum,it);
        }
        return sum;
    }
};