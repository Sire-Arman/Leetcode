class Solution {
public:
    string compressedString(string word) {
        vector<int> freq(26,0);
        string ans = "";
        for(int i=0;i<word.size();i++){
            // cout<<word[i]-'a'<<endl;
            freq[word[i]-'a']++;
            if(freq[word[i]-'a'] == 9 || (i<word.size() && word[i] != word[i+1]) ||(i==word.size()-1)){
                ans.push_back('0'+freq[word[i]-'a']);
                ans.push_back(word[i]);
                freq[word[i]-'a']=0;
            }
        }
        return ans;
    }
};