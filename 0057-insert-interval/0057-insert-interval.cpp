class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ne) {
        vector<vector<int>> res;
        int i =0;
        bool flag = false;
        while(i<in.size()){
            if(ne[0] <= in[i][0]){
                vector<int> arr(2);
                arr[0] = ne[0];
                while(i<in.size() && in[i][0] <= ne[1] && in[i][1] <= ne[1]) i++;
                if( i== in.size()) res.push_back(ne);
                else if(in[i][0] > ne[1]){ res.push_back(ne);}
                else {
                    arr[1] = in[i][1];
                    res.push_back(arr);
                    i++;
                }
                flag = true;
                break;
            }
            else if(ne[0]<= in[i][1]){
                int j = i;
                while(j<in.size() && in[j][0] <= ne[1] && in[j][1] <= ne[1]) j++;
                if(j == in.size()) {res.push_back({in[i][0], ne[1]}); i = j;}
                else if (in[j][0] > ne[1]){ res.push_back({in[i][0], ne[1]}); i = j;}
                else {res.push_back({in[i][0], in[j][1]}); i = j+1;}
                flag = true;
                break;
            }
            else {
                res.push_back(in[i]);
            }
            i++;
        }
        while(i < in.size()){
            res.push_back(in[i]);
            i++;
        }
        if(in.size() == 0 || !flag) res.push_back(ne);
        return res;
    }
};