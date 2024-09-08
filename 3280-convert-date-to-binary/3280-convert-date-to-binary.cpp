class Solution {
public:
    string binary(int a){
        string s ="";
        if(a==0) return "0";
        while(a){
            if(a%2 == 0){
                s += "0";
            }
            else{
                s += "1";
            }
            a/=2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string convertDateToBinary(string d) {
        int a = stoi(d.substr(0,4));
        int b = stoi(d.substr(5,2));
        int c = stoi(d.substr(8,2));
        string ans = "";
        ans += binary(a)+'-' +binary(b)+'-'+binary(c);
        return ans;
    }
};