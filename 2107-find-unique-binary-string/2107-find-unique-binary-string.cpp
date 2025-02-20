class Solution {
public:
    string numtobin(int num){
        if(num==0){
            return "0";
        }
        string ans="";
        while(num){
            char v = num%2 +'0';
            string x(1,v);
            ans+=x;
            num/=2;
        }
        return ans;
    }
    bool find(string temp,vector<string>& nums){
        for(auto it: nums){
            if(it == temp){
                return true;
            }
        }
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int val = pow(2,n)-1;
        while(val){
            string x = numtobin(val);
            if(!find(x,nums)){
                return x;
            }
            val--;
        }
        if(val == 0){
            return "0";
        }
        return "";
    }
};