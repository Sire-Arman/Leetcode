class Solution {
public:
    int strStr(string haystack, string needle) {
        int size = needle.size();
        int size2 = haystack.size();
        for(int i =0;i<size2-size+1;i++){
            if(haystack.substr(i,size) == needle){
                return i;
            }
        }
        return -1;
    }
};