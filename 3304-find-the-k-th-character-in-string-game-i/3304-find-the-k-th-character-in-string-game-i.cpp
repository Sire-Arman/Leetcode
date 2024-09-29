class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        int t = ceil(log2(k));
        for(int i=0;i<=t;i++){
            string x = "";
            for(auto it : s){
                x += static_cast<char>(((it-'a')+1)%26 +'a');
            }
            s+=x;
        }
        return s[k-1];
    }
};