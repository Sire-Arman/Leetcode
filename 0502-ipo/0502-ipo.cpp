class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=size(capital), j=0;
        vector<vector<int>> pro;
        for(int i=0; i<n; i++)pro.push_back({capital[i], profits[i]});
        sort(begin(pro), end(pro));
        priority_queue<int> pq;
        for(int i=0; i<k; i++){
            while(j<n && pro[j][0]<=w)pq.push(pro[j++][1]);
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            }
            else break;
        }
        return w;

    }
};