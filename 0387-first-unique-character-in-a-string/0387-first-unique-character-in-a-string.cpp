class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> arr(26);
        int ind = -1;
        for(int i=s.size()-1;i>=0;i--){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
           if(arr[s[i]-'a']==1) {ind =i; break;}
            
        }
        return ind;
    }
};