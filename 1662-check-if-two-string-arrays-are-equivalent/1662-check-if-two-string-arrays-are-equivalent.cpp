class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        string temp ="",temp2="";
        for(auto it: w1){
            temp+=it;
        }
        for(auto it:w2){
            temp2+=it;
        }
        return temp2 == temp;
    }
};