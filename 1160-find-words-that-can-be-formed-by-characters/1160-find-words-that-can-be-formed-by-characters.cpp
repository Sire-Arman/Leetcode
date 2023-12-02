class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> mp;
        int len=0;
        for(auto it:chars){
            mp[it]++;
        }
        for(auto it: words){
            map<char,int> mp2;
            int flag=1;
            for(auto i: it){
                mp2[i]++;
            }
            for(auto i:mp2){
                char ch=i.first;
                if(i.second > mp[ch]){
                    flag=0;
                    break;
                }
            }
            if(flag) len+=it.size();
        }
        return len;
    }
};