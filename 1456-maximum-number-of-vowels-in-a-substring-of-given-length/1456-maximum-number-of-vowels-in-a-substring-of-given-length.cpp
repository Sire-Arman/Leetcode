class Solution {
public:
    bool isvowel(char it){
         if( it=='a'||it=='e'||it=='i'||it=='o'||it=='u'){
             return true;
         }
        return 0;
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int cnt=0;
        int left =0,right =k-1;
        int maxi = INT_MIN;
        int vowel =0;
        for(int i=0;i<k;i++){
            if(isvowel(s[i])){
                vowel++;
            }
        }
        maxi = max(vowel ,maxi);
        right++;
        left++;
        while(right<n){
            if(isvowel(s[right])){
                vowel++;
            }
            if(isvowel(s[left-1])){
                vowel--;
            } 
            maxi = max(vowel,maxi);
            right++;
            left++;
        }
        return maxi;
    }
};