class Solution {
public:
    string expand(int left , int right,string s){
        while(left>=0 && right <s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }
    string longestPalindrome(string s) {
        if(s.size()<=1){
            return s;
        }
        string max_len =  "";
        max_len += s[0];
        for(int i=0;i<s.size()-1;i++){
            string odd = expand(i,i,s);
            string even = expand(i,i+1,s);
            if(odd.size() > max_len.size()){
                max_len = odd;
            }
            if(even.size() >max_len.size()){
                max_len = even;
            }
        }
        return max_len;
    }
};