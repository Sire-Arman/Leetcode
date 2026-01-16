class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        map<int,int> mp;

        for(auto& it: ranges){
            mp[it[0]]++;
            mp[it[1]]--;
        }
        int idx = left;
        int run_sum =0;
        // while(idx<= right){
            for(auto& it: mp){
                while(idx<=right) {
                if(it.first>idx){
                    if(run_sum <= 0) return false;
                    else idx++;
                }
                else if(it.first == idx){
                    idx++;
                }else break;
                }
                run_sum+=it.second;
            }
        // }
        return idx<=right?false:true;
    }
};