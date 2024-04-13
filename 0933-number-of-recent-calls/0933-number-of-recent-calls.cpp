class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        queue<int> e;
        swap(q,e);
    }
    
    int ping(int t) {
        q.push(t);
        int a = t-3000;
        while(q.front()<a) q.pop();
        return  q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */