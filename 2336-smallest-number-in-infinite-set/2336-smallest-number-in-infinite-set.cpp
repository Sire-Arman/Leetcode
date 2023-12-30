class SmallestInfiniteSet {
public:
    set<int> st;
    priority_queue<int,vector<int>,greater<int>> pq;
    int sml;
    SmallestInfiniteSet() {
        sml=1;
    }
    
    int popSmallest() {
        if(st.size()==0 || sml<=*st.begin()){
            int t= sml;
            if(sml==*st.begin()){
                st.erase(*st.begin());
            }
            sml++;
            return t;
        }
        else{
            int t = *st.begin();
            st.erase(*st.begin());
            return t;
        }
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */