class Solution {
public:
    static bool const cmp(int&a , int &b){
        return a>b;
    }
    int minimumPushes(string word) {
        map<char,int> mp;
        for(auto it : word){
            mp[it]++;
        }
        int n = mp.size();
        vector<int> check(n);
        int k=0;
        for(auto it :mp){
            check[k++] = it.second;
        }
        sort(check.begin(),check.end(),cmp);
        int i =1,j=1;
        int ans =0;
        for(auto it : check){
            ans  += i*it;
            j++;
             if(j>8){
                i++;
                j=1;
            }
        }
        return ans;
    }
};