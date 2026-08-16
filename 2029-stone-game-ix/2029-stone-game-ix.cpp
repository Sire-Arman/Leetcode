class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> freq(3,0);
        for(auto it : stones){
            freq[it%3]++;
        }
        if(freq[0]&1){
            return abs(freq[1] - freq[2])>=3;
        }
        return freq[1]>=1 && freq[2]>=1;
    }
};