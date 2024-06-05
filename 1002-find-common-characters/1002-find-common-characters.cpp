class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> a(26,0);
        vector<int> b(26,0);
        for(auto it : words[0]){
            a[it-'a']++;
        }
        for(int i=1;i<words.size();i++){
            for(auto it: words[i]){
                b[it-'a']++;
            }
            for(int j=0;j<26;j++){
                b[j]=min(a[j],b[j]);
            }
            a = b;
            b = vector<int>(26,0);
        }
        for(int i=0;i<26;i++){
            while(a[i]--){
                int x = 97+i;
                ans.push_back("");
                ans.back()=ans.back()+char(x);
            }
        }
        return ans;
    }
};