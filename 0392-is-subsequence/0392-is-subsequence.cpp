class Solution {
public:
    bool isSubsequence(string t, string s) {
        if(t.size() == 0){
            return true;
        }
        else if( s.size() ==0){
            return false;
        }
        int i=0,j=0;
        while(i<t.size() && j<s.size()){
            if(s[j] == t[i]){
                i++;
            }
            j++;
        }
        cout<<i<<endl;
        if(i<t.size()){
            return false;
        }
        return true;
    }
};