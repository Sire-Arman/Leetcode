class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int p) {
        sort(tokens.begin(),tokens.end());
        int maxi = 0,score=0;
        int l = 0,r = tokens.size()-1;
        // if(r<0) return 0;
        while(l<tokens.size() && tokens[l] != INT_MIN){
            
            if(tokens[l] <= p){
                p -= tokens[l];
                score++;
                maxi = max(maxi,score);
                l++;
            }
            else{
                if(score < 1) break;
                p += tokens[r];
                tokens[r] = INT_MIN;
                r--;
                score--;
            }
        }
        return max(maxi,score);
    }
};