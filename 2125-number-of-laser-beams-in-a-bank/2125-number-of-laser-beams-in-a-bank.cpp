class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> arr;
        for(auto it : bank){
            int cnt=0;
            for(auto i : it){
                if(i=='1') cnt++;
            }
            if(cnt) arr.push_back(cnt);
        }
        if(arr.size()==0) return 0;
        long long ans=0;
        for(int i=0;i<arr.size()-1;i++){
            ans+= arr[i]*arr[i+1];
        }
        return (int)ans;
    }
};