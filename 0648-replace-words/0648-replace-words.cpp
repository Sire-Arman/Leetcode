class Solution {
public:
    string replaceWords(vector<string>& dict, string s) {
        map<string,bool> mp;
        for(auto it : dict){
            mp[it]=true;
        }
        string res = "";
        int i=0;
        while(i<s.size()){
            if(s[i]==' '){
                i++;
                res +=' ';
                continue;
            }
            else{
                int j =i;
                string t ="";
                while(!mp[t] && s[j] !=' ' && j<s.size()){
                    t+=s[j];
                    j++;
                }
                while(s[j]!= ' ' && j<s.size()){
                    j++;
                }
                res+=t;
                i=j;
            }
        }
        return res;
        
    }
};