class Solution {
public:
    vector<string> sortPeople(vector<string>& name, vector<int>& h) {
        priority_queue<pair<int,string>> pq;
        int n = h.size();
        for(int i=0;i<n;i++){
            pq.push({h[i],name[i]});
        }
        int i=0;
        while(!pq.empty()){
            name[i] = pq.top().second;
            pq.pop();
            i++;
        }
        return name;
    }
};