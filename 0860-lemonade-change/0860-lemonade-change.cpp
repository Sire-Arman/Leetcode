class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f =0,t=0;
        for(auto it : bills){
            if(it == 5){
                f++;
            }
            else if (it == 10){
                if(f == 0) return false;
                t++;
                f--;  
            }
            else {
                if(t && f){
                    t--;
                    f--;
                }
                else if (t==0 && f>=3){
                    f-=3;
                }
                else return false;
            }
        }
        return true;
    }
};