class CustomStack {
public:
    vector<int> st;
    int n;
    int last;
    vector<int> chk;
    CustomStack(int maxSize) {
        n = maxSize;
        st.resize(maxSize);
        chk.resize(maxSize);
        last =-1;
    }
    
    void push(int x) {
        if(last == n-1) return;
        last++;
        st[last]=x;
    }
    
    int pop() {
        if(last == -1){
            return last;
        }
        int x = st[last]+chk[last];
        st[last]=0;
        chk[last]=0;
        last--;
        return x;
    }
    
    void increment(int k, int val) {
        if(last == -1) return;
        for(int i=0;i<min(last+1,k);i++){
            chk[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */