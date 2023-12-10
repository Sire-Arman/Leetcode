class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        vector<int> check(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            char it = s[i];
            if( it=='a'||it=='e'||it=='i'||it=='o'||it=='u'){
                cnt++;
            }
            check[i] = cnt;
        }
        int left =0,right =k-1;
        int maxi = INT_MIN;
        while(right<n){
            if(left == 0){
                int vowels = check[right];
                maxi = max(vowels,maxi);
            }
            else{
                int vowels = check[right]-check[left-1];
                maxi = max(vowels,maxi);
            }
            right++;
            left++;
        }
        return maxi;
    }
};