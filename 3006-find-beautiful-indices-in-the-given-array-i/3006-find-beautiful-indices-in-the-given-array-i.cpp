class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        if(a.size()>s.size() || b.size()>s.size()) return {};
        vector<int> ans;
        int i=0;
        int prev = -1;
        while(i<(s.size()-a.size()+1)){
            if(s.substr(i,b.size())== b) prev = i;
            if(s.substr(i,a.size())==a){
                if(prev == -1 || abs(prev-i)>k){
                    int si = s.size()-b.size()+1;
                    for(int j=i;j<= min(si,i+k);j++){
                        if(s.substr(j,b.size()) == b){
                           prev = j; 
                            break;
                        }
                    }
                }
                    if(prev != -1 && abs(prev-i)<=k) {
                        ans.push_back(i);
                    }
            }
            i++;
        }
        return ans;
    }
};