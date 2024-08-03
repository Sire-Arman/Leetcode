class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size() != arr.size()) return false;
        map<int,int> mp;
        for(auto it : target){
            mp[it]++;
        }
        for(auto it : arr){
            mp[it]--;
        }
        for(auto it : mp){
            if(it.second != 0) return false;
        }
        
       return true;
    }
};