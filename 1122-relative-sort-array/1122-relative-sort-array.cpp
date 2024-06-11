class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        int i=0;
        for(auto it : arr2){
            while(mp[it]--){
                arr1[i] = it;
                i++;
            }
        }
        for(auto it : mp){
            while(it.second >0){
                arr1[i] = it.first;
                i++;
                it.second--;
            }
        }
        return arr1;
    }
};