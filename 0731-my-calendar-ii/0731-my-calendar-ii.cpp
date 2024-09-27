class MyCalendarTwo {
public:
    vector<pair<int,int>> douuble;
    vector<pair<int,int>> single;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto it : douuble){
            if(max(start,it.first) < min(end, it.second)){
                return false;
            }
        }
        for(auto it : single){
            if(max(start,it.first) < min(end, it.second)){
                douuble.push_back({max(start,it.first) , min(end, it.second)});
            }
        }
        single.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */