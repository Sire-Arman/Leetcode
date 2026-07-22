class SegTree{
    public: 
    int n,maxLog;
    string s;
    vector<vector<int>> a;
    SegTree(string s){
        this->s = s;
        n = s.size();
        maxLog = log2(n);
        a.assign(n,vector<int>(maxLog+1));
        for(int i=0;i<n;i++){
            a[i][0] = s[i]-'0';
        }    
    }
    void preprocess(){
        for(int j =1;j<=maxLog;j++){
            for(int i =0;i+(1<<j)-1<n;i++){
                a[i][j] = max(a[i][j-1],countActiveInRange(i+(1<<(j-1)),j-1));
            }
        }
    }
    long long query(int l, int r){
        int len = r-l+1;
        int j =0;
        while((1<<(j+1))<=len) j++;
        return max(a[l][j],a[r-(1<<j)+1][j]);
    }
    int countActiveInRange(int l, int r){
        int i =l;
        int prev=INT_MIN;
        int maxi =0;
        int ans =0;
        while(i<=r){
            int j = i+1;
            while(j<=r && s[i]==s[j]) j++;
            int cur = j-i;
            if(s[i]=='1'){
                ans +=cur;
            }
            else{
                maxi = max(prev+cur,maxi);
                prev=cur;
            }
            i=j;
        }
        return ans+maxi;
    } 
};
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        // 1. Prefix sums for counting '1's in O(1)
        vector<int> pref1(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref1[i + 1] = pref1[i] + (s[i] == '1' ? 1 : 0);
        }
        int totalOnesFull = pref1[n];               // <-- NEW: ones in the whole string
        // 2. Identify all zero-blocks
        vector<int> blockId(n, -1);
        vector<int> startIdx, endIdx, L;
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j++;
                int bId = startIdx.size();
                startIdx.push_back(i);
                endIdx.push_back(j - 1);
                L.push_back(j - i);
                for (int k = i; k < j; k++) blockId[k] = bId;
                i = j;
            } else {
                i++;
            }
        }
        int M = startIdx.size();
        // 3. Map positions to nearest zero-block IDs
        vector<int> nextBlockId(n, M);
        vector<int> prevBlockId(n, -1);
        int curr = M;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') curr = blockId[i];
            nextBlockId[i] = curr;
        }
        curr = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') curr = blockId[i];
            prevBlockId[i] = curr;
        }
        // 4. Sparse Table over adjacent zero-block sums: V[i] = L[i] + L[i+1]
        int K = (M >= 2 ? M - 1 : 0);
        vector<int> lg;
        vector<vector<int>> st;
        if (K > 0) {
            lg.assign(K + 1, 0);
            for (int i = 2; i <= K; i++) lg[i] = lg[i / 2] + 1;
            int maxLog = lg[K];
            st.assign(maxLog + 1, vector<int>(K));
            for (int i = 0; i < K; i++) {
                st[0][i] = L[i] + L[i + 1];
            }
            for (int j = 1; j <= maxLog; j++) {
                for (int i = 0; i + (1 << j) <= K; i++) {
                    st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
                }
            }
        }
        auto queryV = [&](int l, int r) {
            int j = lg[r - l + 1];
            return max(st[j][l], st[j][r - (1 << j) + 1]);
        };
        // 5. Process range queries
        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int totalOnes = pref1[r + 1] - pref1[l];
            int outsideOnes = totalOnesFull - totalOnes;   // <-- NEW: ones outside [l, r]
            int first = (s[l] == '0' ? blockId[l] : nextBlockId[l]);
            int last  = (s[r] == '0' ? blockId[r] : prevBlockId[r]);
            // Case A: 0 zero-blocks inside range -> whole range already active
            if (first == -1 || first >= M || first > last) {
                ans.push_back((r - l + 1) + outsideOnes);
                continue;
            }
            // Case B: Exactly 1 zero-block inside range -> NO valid trade possible
            // (a trade needs a '1'-block sandwiched between two '0'-blocks to convert away),
            // so the best we can do is keep the ones that are already there.
            if (first == last) {
                ans.push_back(totalOnes + outsideOnes);      // <-- FIXED (was r - l + 1)
                continue;
            }
            // Case C: 2 or more zero-blocks
            int L_first_prime = endIdx[first] - max(startIdx[first], l) + 1;
            int L_last_prime  = min(endIdx[last], r) - startIdx[last] + 1;
            int maxGain = 0;
            if (last == first + 1) {
                maxGain = L_first_prime + L_last_prime;
            } else {
                // Check boundary pairs
                maxGain = max(L_first_prime + L[first + 1], L[last - 1] + L_last_prime);
                // Check interior fully-contained adjacent pairs via Sparse Table
                if (last - 2 >= first + 1) {
                    maxGain = max(maxGain, queryV(first + 1, last - 2));
                }
            }
            ans.push_back(totalOnes + maxGain + outsideOnes);   // <-- FIXED (added outsideOnes)
        }
        return ans;
    }
};