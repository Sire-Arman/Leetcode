class Solution {
public:
    void insert(vector<string> &ans, int a){
        for(int i=0;i<a;i++){
            ans.push_back("Push");
        }
        for(int i=0;i<a;i++){
            ans.push_back("Pop");
        }
    }
    vector<string> buildArray(vector<int>& target, int n){
        int lastval=1;
        vector<string> ans;
        for(int i=0;i<target.size();i++){
            int currval = target[i];
            insert(ans,currval-lastval);
            ans.push_back("Push");
            lastval = currval+1;
        }
        return ans;
    }
};