class Solution {
public:
    int minOperations(vector<string>& logs) {
        int len = 0;
        for(auto it : logs){
            if(it[1]=='.'){
                if(len != 0) len--;
            }
            else if (it[0] != '.'){
                len++;
            }
        }
        return len;
    }
};