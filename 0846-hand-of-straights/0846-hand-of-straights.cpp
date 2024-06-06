class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        map<int,int> mp;
        for(auto it : hand){
            mp[it]++;
        }
        for(auto it : mp){
            while(it.second--){
                int x = it.first;
                for(int i=0;i<g;i++){
                    if(!mp[x]) return false;
                    mp[x]--;
                    x++;
                }
            }
        }
        return true;
    }
};