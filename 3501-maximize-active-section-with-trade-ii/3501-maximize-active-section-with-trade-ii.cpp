class SegTree{
    public:
    int n;
    vector<int> st;
    SegTree(vector<int> pairs){
        n = pairs.size();
        st.assign(4*max(n,1),0);          // avoid a zero-size tree
        if(n>0) build(pairs,1,0,n-1);
    }
    int build(vector<int>& pairs,int node, int l, int r){
        if(l==r) return st[node]=pairs[l];
        int mid = l+(r-l)/2;
        int lc = build(pairs,node*2,l,mid);
        int rc = build(pairs,node*2+1,mid+1,r);
        return st[node] = max(lc,rc);
    }
    int query(int node, int l, int r, int ql, int qr){
        if(ql>qr) return 0;
        if(qr<l || r<ql) return 0;
        if(l>=ql && r<=qr) return st[node];
        int mid = l+(r-l)/2;
        int lc = query(node*2,l,mid,ql,qr);
        int rc = query(node*2+1,mid+1,r,ql,qr);
        return max(lc,rc);
    }
};
class Solution {
public:
    int binarySearchLeft(int t, vector<int>& ends){
        int l=0,r=ends.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(t == ends[mid]) return mid;
            else if(t<= ends[mid]){
                r = mid;
            }
            else l = mid+1;
        }
        return l;
    }
    int binarySearchRight(int t, vector<int>& starts){
        int l =0,r = starts.size()-1;
         while(l<=r){
            int mid = l + (r-l)/2;
            if(t == starts[mid]) return mid;
            else if(t<= starts[mid]){
                r = mid;
            }
            else l = mid+1;
        }
        return r;
    }
    int idxAt(int pos, vector<pair<int,int>>& zeroes){
        int lo=0, hi=(int)zeroes.size()-1, res=-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(zeroes[mid].first <= pos){ res=mid; lo=mid+1; }
            else hi=mid-1;
        }
        return res;
    }
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size(),prev=0,cur=0,ones=0;
        vector<int> ans;
        vector<int> prefix(n+1,0);
        vector<pair<int,int>> zeroes;
        vector<int> starts,ends;
        vector<int> pairs;
        for(int i=0;i<n;){
            if(s[i]=='0'){
                int j=i;
                while(j<n && s[j]=='0') j++;
                zeroes.push_back({i,j-1});
                i=j;
            } else { ones++; i++; }
        }

        for(int k=0;k+1<(int)zeroes.size();k++){
            int len1 = zeroes[k].second - zeroes[k].first + 1;
            int len2 = zeroes[k+1].second - zeroes[k+1].first + 1;
            pairs.push_back(len1+len2);
        }
        if(zeroes.empty()){ ans.assign(queries.size(), ones); return ans; }
        for(auto [s,e] : zeroes){
            starts.push_back(s);
            ends.push_back(e);
        }
        if(prev && cur) pairs.push_back(prev+cur);
        SegTree sg(pairs);
        for(auto& q : queries){
            int l=q[0], r=q[1];
            int gl = idxAt(l, zeroes);
            int gr = idxAt(r, zeroes);

            int left  = (gl==-1) ? -1 : (zeroes[gl].second - l + 1);
            int right = (gr==-1) ? -1 : (r - zeroes[gr].first + 1);

            int startAdj = gl + 1;
            int Bend     = (s[r]=='1') ? gr : gr - 1;   // last fully-interior run index
            int endAdj   = Bend - 1;                    // last usable pair index

            int best = ones;

            if(s[l]=='0' && s[r]=='0' && gl+1==gr){
                best = max(best, ones + left + right);
            } else if(startAdj <= endAdj && startAdj>=0 && endAdj<(int)pairs.size()){
                best = max(best, ones + sg.query(1,0,(int)pairs.size()-1,startAdj,endAdj));
            }
            if(s[l]=='0' && gl+1 < (int)zeroes.size() && gl+1 <= Bend){
                int nextLen = zeroes[gl+1].second - zeroes[gl+1].first + 1;
                best = max(best, ones + left + nextLen);
            }
            if(s[r]=='0' && gr-1 >= 0 && gl < gr-1){
                int prevLen = zeroes[gr-1].second - zeroes[gr-1].first + 1;
                best = max(best, ones + right + prevLen);
            }

            ans.push_back(best);
        }
        return ans;
    }
};