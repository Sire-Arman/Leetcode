class Solution {
public:
    void factors(int n,vector<int>& fct) 
{ 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
                fct.push_back(i);
  
            else{
                fct.push_back(i);
                fct.push_back(n/i);}
        } 
    } 
} 
    bool check(string &s, int b){
        int n = s.size();
            int a1[26] = {0};
        for(int i=0;i<b;i++)
            a1[s[i]-'a']++;
            for(int j = b;j<n;j+=b){
                int a2[26] = {0};
                for(int x = 0;x<b;x++){
                a2[s[j+x]-'a']++;
                }
                for(int x= 0;x<26;x++){
                    if(a1[x] != a2[x]) return false;
                }
            }
            return true;
    }
    int minAnagramLength(string s) {
        vector<int> fct;
        int n = s.size();
        factors(n,fct);
        int sum =0;
        int res = n;
        sort(fct.begin(),fct.end());
        // for(auto it : fct) cout<<it<<' ';
        for(int i=0;i<fct.size();i++){
            if(check(s,fct[i])) return fct[i];
        }
        return res;
    }
};