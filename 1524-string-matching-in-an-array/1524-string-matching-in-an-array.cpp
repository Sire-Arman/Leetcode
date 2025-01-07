class Solution {
public:
static bool cmp(string& a, string &b){
    return a.size()<b.size();
}
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            string t = words[i];
            for(int j=i+1;j<words.size();j++){
                if(words[j].find(t) != -1) {ans.push_back(t);break;}
            }
        }
        return ans;
    }
};