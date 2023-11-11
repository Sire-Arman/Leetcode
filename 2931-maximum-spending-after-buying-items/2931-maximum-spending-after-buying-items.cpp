class Solution {
public:
    // static bool cmp(pair<int,int> &a,pair<int,int> &b){
    //     return 
    // }
    long long maxSpending(vector<vector<int>>& values) {
        int m = values.size();
        int n = values[0].size();
        int index = n-1;
        long long days = 1;
        long long sum = 0;
        int mod = 1e9+7;
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
            for(int i=0;i<m;i++){
                pq.push(make_pair(values[i][index],make_pair(i,index)));
                
            }
            while(!pq.empty()){
                sum = (sum + (long long)(pq.top().first)*days);
                int val = pq.top().second.second;
                int fir = pq.top().second.first;
                pq.pop();
                if(val>0){
                    pq.push(make_pair(values[fir][val-1],make_pair(fir,val-1)));
                }
                days++;
            }
        return sum;
    }
};