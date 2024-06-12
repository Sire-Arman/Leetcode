class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n1 = nums1.size(),n2= nums2.size();
        set<pair<int,int>> st;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({nums1[0]+nums2[0],{0,0}});
        st.insert({0,0});
        while(k-- && !pq.empty()){
            auto [a,b] = pq.top().second;
            pq.pop();
            ans.push_back({nums1[a], nums2[b]});
            if(a+1 < n1 && st.find({a+1,b})== st.end()){
                pq.push({nums1[a+1]+nums2[b], {a+1,b}});
                st.insert({a+1,b});
            }
            if(b+1<n2 && st.find({a,b+1}) == st.end()){
                pq.push({nums1[a]+nums2[b+1],{a,b+1}});
                st.insert({a,b+1});
            }
        }
        return ans;
    }
};