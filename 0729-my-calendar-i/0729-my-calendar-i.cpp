class MyCalendar {
public:
    set<pair<int,int>> st;
    int n;
    MyCalendar() {
        n=0;
    }
    
    bool book(int start, int end) {
        for(auto it : st){
            if(start < it.second && end > it.first ){
                return false;
            }
        }
        st.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */