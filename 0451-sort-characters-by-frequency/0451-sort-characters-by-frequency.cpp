class Solution {
public:
    string frequencySort(string s) {
        map<char,int> freq;
        for(auto it : s){
            freq[it]++;
        }
        map<int,set<char>> mp;
        for(auto it : freq){
            mp[it.second].insert(it.first);
        }
        string temp = "";
        for(auto it : mp){
            for(auto i : it.second){
                int x = it.first;
                while(x--){
                temp += i;
                }
            }
        }
        reverse(temp.begin(),temp.end());
        return temp;

    }
};