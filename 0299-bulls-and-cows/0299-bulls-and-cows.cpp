class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int> mp;
        for(int i=0;i<secret.size();i++){
            mp[secret[i]]++;
        }
        string ans ="";
        int bulls =0,cows =0;
        for(int i=0;i<guess.size();i++){
         if(mp[guess[i]] && secret[i] == guess[i]){
             bulls++;
             mp[secret[i]]--;
         }   
            
        }
        for(int i=0;i<guess.size();i++){
            if(secret[i] == guess[i]) continue;
        if(mp[guess[i]]){
                cows++;
                mp[guess[i]]--;
            }
        }
        ans += to_string(bulls)+'A';
        ans += to_string(cows)+'B';
        return ans;
    }
};