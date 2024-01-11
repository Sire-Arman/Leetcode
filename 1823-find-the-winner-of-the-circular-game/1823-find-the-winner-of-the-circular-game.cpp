class Solution {
public:
    int findTheWinner(int n, int k) {
        set<int> st;
        for(int i=1;i<=n;i++){
            st.insert(i);
        }
        set<int>::iterator it = st.begin();
        while(st.size() != 1){
            int a = (k%st.size()-1);
            if(k==st.size()) a = k-1;
            if(a<0) a=k-1;
            while(a--){
                it++;
                if(it == st.end()){
                    it = st.begin();
                }
            }
            int val = *it;
            it++;
            if(it == st.end()){
                    it = st.begin();
                }
            st.erase(val);
        }
        return *st.begin();
    }
};