class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
//         map<char,int> mp;
//         int time =1;
//         priority_queue<pair<int,char>,vector<pair<int,char>>, greater<pair<int,char>>> pq;
//         for(auto it : tasks){
//             mp[it]++;
//         }
//         for(auto it : mp){
//             pq.push({0,it.first});
//         }
//         while(!pq.empty()){
//             auto [a,b] = pq.top();
//             pq.pop();
//             if(a == 0){
//                 mp[b]--;
//                 if(mp[b]) pq.push({time+n,b});
 
//             }
//             else{
//                 while(time<=a){
//                     time++;
//                 }
//                 mp[b]--;
//                 if(mp[b]) {pq.push({time+n,b});}
                
//             }
//             time++;
//         }
//         return time-1;
        
        vector<int> freq(26,0);
        for(auto it : tasks){
            freq[it-'A']++;
        }
        sort(freq.begin(),freq.end());
        int ans = freq[25]-1;
        int free = ans*n;
        for(int i = 24;i>=0;i--){
            free -= min(freq[i], ans);
        }
        return free<0 ? tasks.size(): tasks.size()+free;
    }
};