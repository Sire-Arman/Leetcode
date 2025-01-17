class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        // cout<<count(d.begin(),d.end(),1)<<endl;
       return !(count(d.begin(),d.end(),1)&1);
    }
};