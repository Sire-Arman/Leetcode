class Solution {
public:
    string getEncryptedString(string s, int k) {
        string temp = s;
        for(int i=0;i<s.size();i++){
            s[i] = temp[(i+k)%s.size()];
        }
        return s;
    }
};