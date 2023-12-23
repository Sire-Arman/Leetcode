class Solution {
public:
    bool isPathCrossing(string s) {
        map<pair<int,int>,bool> mp;
        pair<int,int> p = make_pair(0,0);
        mp[p] = true;
        for(int i=0;i<s.size();i++){
            if(s[i] =='N'){
                p.second++;
            }
            if(s[i] =='E'){
                p.first++;
            }
            if(s[i] =='S'){
                p.second--;
            }
            if(s[i] =='W'){
                p.first--;
            }
            if(mp[p] == true) return true;
            else{
                 mp[p] = true;
            }
        }
        return false;
    }
};