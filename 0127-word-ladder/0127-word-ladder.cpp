class Solution {
public:
    int bfs(string b, string e, unordered_set<string>& st,queue<pair<string,int>>& q){
        while(!q.empty()){
            string temp = q.front().first;
            int step = q.front().second;
            st.erase(temp);
            q.pop();
            for(int j=0;j<temp.size();j++){
                char ch = temp[j];
                for(char i='a';i<='z';i++){
                    temp[j] = i;
                    if(st.find(temp) != st.end()){
                        if(temp == e) return step+1;
                        else q.push({temp,step+1});
                    }
                }
                temp[j] = ch;
            }
        }
        return 0;
    }
    int ladderLength(string b, string e, vector<string>& wl) {
        queue<pair<string,int>> q;
        q.push({b,1});
        unordered_set<string> st(wl.begin(),wl.end());
        // if(st.find(b) == st.end()) return 0;
        return bfs(b,e,st,q);
    }
};