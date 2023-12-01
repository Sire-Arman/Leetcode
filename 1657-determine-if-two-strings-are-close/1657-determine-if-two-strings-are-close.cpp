class Solution {
public:
    bool closeStrings(string w1, string w2){
        if(w1.size()!=w2.size()){
            return false;
        }
        vector<int> arr1(26,0);
        for(int i=0;i<w1.size();i++){
            arr1[w1[i]-'a']++;
        }
        vector<int> arr2(26,0);
        for(int i=0;i<w2.size();i++){
            arr2[w2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(arr1[i] != 0 && arr2[i]==0 || arr1[i] == 0 && arr2[i]!=0){
                return false;
            }
        }
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end()); 
        
        return arr1 ==  arr2;
    }
};