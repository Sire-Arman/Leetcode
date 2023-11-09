class Solution {
public:
   int play(vector<int> &nums, int l, int r, int turn, int score){
       if(l==r) return score += turn*nums[l];
       int ans;
       if(turn == 1){
           ans = max(nums[l]+play(nums,l+1,r,(turn*-1), score),
                      nums[r]+play(nums,l,r-1,(turn*-1),score));
       }
       else{
           ans = min(-nums[l]+play(nums,l+1,r,(turn*-1), score),
                      -nums[r]+play(nums,l,r-1,(turn*-1),score));
       }
       return ans;
   } 
    bool predictTheWinner(vector<int>& nums) {
        return play(nums,0,nums.size()-1,1,0)>=0;
    }
};