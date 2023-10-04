#define ll unsigned long long
class Solution {
public:
    bool anagram(string a, string b){
        if(a.size()!= b.size()){
            return false;
        }
    ll prod1 =1,prod2 =1;  
    ll sum1 =0,sum2 =0;
        for(auto it :a){
            prod1 *= it;
            sum1 +=it;
        }
        for(auto it :b){
            prod2 *= it;
            sum2 +=it;
        }
        if(prod1== prod2 && sum1 == sum2){
            return true;
        } 
        return false;
        
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
       for(int i = 0;i<strs.size();i++){
           if(strs[i] == "0"){
               continue;
           }
           vector<string> ans;
           ans.push_back(strs[i]);
          for(int j = i+1;j<strs.size();j++){
              if(anagram(strs[i], strs[j])){
                  ans.push_back(strs[j]);
                  strs[j] = "0";
              }
          }
           
           res.push_back(ans);
       } 
        return res;
    }
};