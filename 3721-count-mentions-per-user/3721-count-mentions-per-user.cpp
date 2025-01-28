class Solution {
public:
    static const bool cmp(vector<string>& a, vector<string>& b){
        if(a[1] != b[1]){
            return stoi(a[1])<stoi(b[1]);
        }
        else{
            return a[0]>b[0];
        }
    }
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int> mention(n);
        sort(events.begin(),events.end(),cmp);
        int all =0;
        unordered_map<int,int> mp;
        for(auto& it: events){
            // cout<<it[0]<<it[1]<<it[2]<<endl;
            if(it[0]=="MESSAGE"){
                int time = stoi(it[1]);
                if(it[2]=="ALL"){
                    all++;
                }
                else if (it[2] == "HERE"){
                    for(int i=0;i<n;i++){
                        if(mp[i] != 0 && time - mp[i]<60) continue;
                        mention[i]++;
                    }
                }
                else{
                    int j =0;
                    for(int i=0;i<it[2].size();i++){
                        if(it[2][i]=='d') j=i;
                        if(it[2][i]==' '){
                            string inds = (it[2].substr(j+1,i-j-1));
                            int ind = stoi(inds);
                            mention[ind]++;
                        }
                        else if (i==it[2].size()-1){
                            string inds = (it[2].substr(j+1,i-j));
                            int ind = stoi(inds);
                            mention[ind]++;
                        }
                    }
                }
            }
            else{
                int ind = stoi(it[2]);
                int time = stoi(it[1]);
                mp[ind] = time;
            }
        }
        for(auto &it: mention){
            it+= all;
        }
        return mention;
    }
};