class Solution {
public:
    static bool cmp(int&a, int& b){
        return a>b;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp = score;
        sort(temp.begin(), temp.end(),cmp);
        map<int,int>mp;
        for(int i=0;i<temp.size();i++){
            mp[temp[i]] = i;
        }
        vector<string> ans;
        for(auto it : score){
            if(mp[it] == 0){
                ans.push_back("Gold Medal");
            }
            else if(mp[it] == 1){
                ans.push_back("Silver Medal");
            }
            else if(mp[it] == 2){
                ans.push_back("Bronze Medal");
            }
            else{
                ans.push_back(to_string(mp[it]+1));
            }
        }
        return ans;
    }
};