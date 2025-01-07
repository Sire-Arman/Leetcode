class Solution {
public:
vector<int> findPrefix(string pattern)
{
    int m=pattern.size();
    vector<int> prefix(m);
    prefix[0]=0;
    int len=0;
    int j=0;
    int i=1;
    while(i<m){
        if(pattern[i] == pattern[j]){
            j++;
            prefix[i] = j;
            i++;
        }
        else{
           if(j>0){
               j = prefix[j-1];
           }
           else{
               prefix[i] = 0;
               i++;
           }
        }
    }   
    return prefix;
}
int KMP(string t, string p){
    int n = t.size();
    int m = p.size();
    vector<int> prefix = findPrefix(p);
    // for(auto it : prefix) cout<<it<<' ';
    int j =0,i=0;
    int ans = -1;
    while(i<n){
        if(t[i] == p[j]){
            i++;
            j++;
            if(j==m){
                ans = i-j;
                return ans;
            }
        }
        else{
            if(j>0) j = prefix[j-1];
            else{
                i++;
            }
        }
    }

    return ans;
}
static bool cmp(string& a, string &b){
    return a.size()<b.size();
}
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            string p = words[i];
            // cout<<p<<endl;
            for(int j=i+1;j<words.size();j++){
                string t = words[j];
                if(KMP(t,p) != -1) {ans.push_back(p);break;}
            }
        }
        return ans;
    }
};