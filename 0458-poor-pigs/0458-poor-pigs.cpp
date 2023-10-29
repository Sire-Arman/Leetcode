class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets == 1){
            return 0;
        }
        int test = minutesToTest/minutesToDie;
        return ceil(log2(buckets)/log2(test+1));
    }
};