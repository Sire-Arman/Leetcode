class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        string curr = "";
        int i =0,n=s.size(),m=part.size();
        bool swap = false;
        while(true){
            if(i+m>s.size()){
                if(swap==false) return s;
                i=0;swap=false;
            }
            else{
                if(s.substr(i,m)==part){
                    s.erase(i,m);
                    swap = false;
                    i=0;
                }
                else i++;
            }
        }
        return s;
    }
};