class Solution {
public:
    int kthGrammar(int n, int k) {
         if(n==1){
             return 0;
         }
//         previous row ki length
        int length = pow(2,n-2);
//         chck first half ya second
        if(k<=length) return kthGrammar(n-1,k);
//         1- is done to reverse the result
        else return 1-kthGrammar(n-1,k-length);
    }
};