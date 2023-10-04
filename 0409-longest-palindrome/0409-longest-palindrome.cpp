class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        int count=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto it : mp){
            if(it.second%2 !=0){
                count++;
            }
        }
        if(count >1){
            return s.size()-count+1;
        }
        return s.size();
    }
};