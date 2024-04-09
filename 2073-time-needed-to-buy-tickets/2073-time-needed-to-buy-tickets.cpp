class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        queue<int> q;
        int n = t.size();
        int time =0;
        for(int i =0;i<=k;i++){
            if(i == k) q.push(INT_MAX);
            else {
                q.push(t[i]);
            }
        }
        int a = t[k];
        if(t[k] == 1) return k+1;
        for(int i = k+1;i<n;i++){
            q.push(t[i]);
        }
        while(!q.empty() && a>0){
            int b = q.front();
            q.pop();
            time++;
            if(b == INT_MAX){
                a--;
                if(a>0) q.push(INT_MAX);
                else return time;
            }
            else if(b>1) q.push(--b);
        }
        return time;
    }
};