class Solution {
public:
    int solve(vector<string>& garbage, vector<int>& travel ,char ch){
        
        int m=0,flag=0;
        int dist=0;
        m += count(garbage[0].begin(),garbage[0].end(),ch);
        if(m) flag=1;
        
        for(int i=1;i<garbage.size();i++){
            dist += travel[i-1];  
            if(count(garbage[i].begin(),garbage[i].end(),ch) != 0){
                flag=1;
                m+= count(garbage[i].begin(),garbage[i].end(),ch) + dist;
                dist=0;
            }
        }
        if(flag == 0){
            return 0;
        }
        return m;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans=0;
        ans+= solve(garbage,travel,'M');
        ans+= solve(garbage,travel,'P');
        ans+= solve(garbage,travel,'G');
        
        
        return ans;
    }
};