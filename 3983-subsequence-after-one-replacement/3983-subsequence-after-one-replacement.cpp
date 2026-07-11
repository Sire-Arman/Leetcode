class Solution {
public:
     bool solve(string s, string t){
        int n = s.size(), m = t.size();
        if (n - 1 > m) return false;          // can't fit even after removing one char
        // fwd[i] = last index used in t after greedily matching s[0..i-1] from the left
        // fwd[0] = -1  (empty prefix, nothing consumed)
        vector<int> fwd(n + 1);
        fwd[0] = -1;
        for (int i = 1; i <= n; i++) {
            int pos = fwd[i - 1] + 1;
            while (pos < m && t[pos] != s[i - 1]) pos++;
            fwd[i] = pos;                     // m ⟹ prefix not matchable
        }
        // whole s is already a subsequence
        if (fwd[n] < m) return true;
        // bwd[i] = first index used in t when greedily matching s[i..n-1] from the right
        // bwd[n] = m  (empty suffix, nothing consumed)
        vector<int> bwd(n + 1);
        bwd[n] = m;
        for (int i = n - 1; i >= 0; i--) {
            int pos = bwd[i + 1] - 1;
            while (pos >= 0 && t[pos] != s[i]) pos--;
            bwd[i] = pos;                     // -1 ⟹ suffix not matchable
        }
        // try removing character i
        for (int i = 0; i < n; i++) {
            if (fwd[i] < m && bwd[i + 1] >= 0 && fwd[i]+1 < bwd[i + 1])
                return true;
        }
        return false;
     }
    int firstSubsequence(string a, string b){
        int i =0,j=0;
        int n = a.size(),m = b.size();
        if(n==0) return -1;
        while(i<n && j<m){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else j++;
        }
        if(i==n) return j-1;
        return INT_MIN;
    }
    int lastSubsequence(string a, string b){
        reverse(a.begin(),a.end());
        int n = a.size(),m = b.size();
        if(n == 0) return b.size();
        int i =0,j=m-1;
        while(i<n && j>=0){
            if(a[i] == b[j]){
                i++;
                j--;
            }
            else j--;
        }
        if(i==n) return j+1;
        return -1;
    }
    bool canMakeSubsequence(string s, string t) {
        // int n = s.size();
        // vector<string> prefix(n+1),suffix(n+1);
        // for(int i =0;i<n;i++){
        //     prefix[i+1] = prefix[i]+s[i];
        // }
        // for(int i=n-1;i>=0;i--){
        //     suffix[i] = s[i]+suffix[i+1];
        // }
        // if(s.size()>t.size()) return false;
        // if(firstSubsequence(s,t) != INT_MIN) return true;
        // for(int i =0;i<n;i++){
        //     string a = prefix[i];
        //     string b = suffix[i+1];
        //     int first = firstSubsequence(a,t);
        //     int last = lastSubsequence(b,t);
        //     if(first != INT_MIN && last != -1 && (first+1)<last) return true;
        // }
        // return false;
        return solve(s,t);
    }
};