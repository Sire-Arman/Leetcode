class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }
    int solve(vector<vector<int>>& en){
        int n = en.size();
        vector<int> arr;
        arr.push_back(en[0][1]);
        for(int i=0;i<n;i++){
            if(en[i][1] > arr.back()){
                arr.push_back(en[i][1]);
            }
            else{
                int ind = lower_bound(arr.begin(), arr.end(), en[i][1])-arr.begin();
                arr[ind] = en[i][1]; 
            }
        }
        return arr.size();
    }
    int maxEnvelopes(vector<vector<int>>& en) {
        sort(en.begin(),en.end(),cmp);
        int ans = solve(en);
        return ans;
    }
};