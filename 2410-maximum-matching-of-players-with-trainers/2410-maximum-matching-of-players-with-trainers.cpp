class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(),p.end());
        sort(t.begin(),t.end());
        
        int j=0,cnt=0;
        for(int i=0;i<p.size();i++){
            while(j<t.size() && p[i] > t[j]){
                j++;
            }
            if(j==t.size()) break;
            cnt++;
            j++;
        }
        return cnt;
    }
};