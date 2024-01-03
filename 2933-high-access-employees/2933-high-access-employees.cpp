class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& act ) {
        map<string,vector<int>> mp;
        for(int i=0;i<act.size();i++){
            mp[act[i][0]].push_back(stoi(act[i][1]));
        }
        vector<string> ans;
        for(auto it : mp){
            if(it.second.size()<3) continue;
            vector<int> temp = it.second;
            sort(temp.begin(),temp.end());
            for(int i=0;i<temp.size()-2;i++){
                if(temp[i+1]-temp[i] <100 && temp[i+2]-temp[i]<100){
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;
    }
};