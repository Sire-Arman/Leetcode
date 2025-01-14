class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int> mp1,mp2;
        int n = B.size();
        vector<int>ans(n);
        for(int i = 0;i<n;i++){
            mp1[A[i]]++;
            mp2[B[i]]++;
            int cnt = 0;
            if(mp1[B[i]]) cnt++;
            if(mp2[A[i]]) cnt++;
            if(A[i]==B[i]) cnt--;
            if(i==0) ans[i]=cnt;
            else ans[i] = ans[i-1]+cnt;
        }
        return ans;
    }
};