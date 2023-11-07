class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string temp="";
        string ans="";
        int index=0;
        while(s[index]==' '){
            index++;
        }
        for(int i=n-1;i>=index;i--){
            if(s[i]==' ' && temp != ""){
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=' ';
                cout<<1<<" ";
                temp="";
            }
            else if(s[i]!=' '){
                temp.push_back(s[i]);
            }
        }
        reverse(temp.begin(),temp.end());
                ans+=temp;
        return ans;
        
    }
};