class Solution {
public:
    string maximumBinaryString(string binary) {
        int count =0,first;
        for(int i=binary.size()-1;i>=0;i--){
            if(binary[i] == '0'){
                count++;
                first =i;
            }
            binary[i] ='1';
        }
        if(!count){
            return binary;
        }
        binary[first + count-1]='0';
        return binary;
    }
};