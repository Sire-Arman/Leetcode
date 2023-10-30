class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> res;
        for(auto it : arr){
            int val = it;
            int bits =0;
            while(val){
                int rem = val%2;
                val/=2;
                if(rem ==1) bits++;
            }
            res.push_back(make_pair(bits,it));
        }
        vector<int> ans;
        sort(res.begin(),res.end());
        for(auto it : res){
            ans.push_back(it.second);
        }
        return ans;
    }
};