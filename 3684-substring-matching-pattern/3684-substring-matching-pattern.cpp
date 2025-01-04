class Solution {
public:
    bool find(string s, string t, int& ind){
        int n = t.size();
        for(int i=ind;i<s.size()-n+1;i++){
            if(s.substr(i,n) == t){
                ind = i;
                return true;
            }
        }
        return false;
    }
    bool hasMatch(string s, string p) {
        int ind = -1;
        for(int i=0;i<p.size();i++){
            if(p[i]=='*'){
                ind = i;
                break;
            }
        }
        int i = ind;
        string a = p.substr(0,i);
        string b = p.substr(i+1,p.size()-i-1);
        ind =0;
        if(a==""){
            return find(s,b,ind);
        }
        if(b==""){
            return find(s,a,ind);
        }
        
        bool x = find(s,a,ind);
        ind += a.size();
        
        return x && find(s,b,ind);
    }
};