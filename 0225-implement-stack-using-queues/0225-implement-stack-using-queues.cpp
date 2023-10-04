class MyStack {
public:
    using int02 = pair<int,int>;
    priority_queue<int02> q;
    int counter =0;
    MyStack() {
    }
    
    void push(int x) {
        q.push({counter++,x});
    }
    
    int pop() {
        int t = q.top().second;
        counter--;
        q.pop();
        return t;
    }
    
    int top() {
        return q.top().second;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */