class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        string t = "";
        bool flag = true;
        vector<char> alpha = { '1','a', 'b', 'c', 'd', 'e', 'f', 'g', 
                             'h', 'i', 'j', 'k', 'l', 'm', 'n', 
                             'o', 'p', 'q', 'r', 's', 't', 'u', 
                             'v', 'w', 'x', 'y', 'z'};
        for(int i =0;i<n;i++){
               bool flag = true;
           for(int j=1;j<27;j++){
               int a = abs(alpha[j]-s[i]);
               int diff = min(a, (26-a));
               // cout<<diff<<endl;
               if(diff <= k){
                   t.push_back(alpha[j]);
                   k-= diff;
                   flag = false;
                   break;
               }
           }
            if(flag){
                    t.push_back(s[i]);
                }
        }
        
        return t;
    }
};