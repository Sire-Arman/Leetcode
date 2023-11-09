class MinStack {
public:
    deque<int> arr;
    int i_top;
    MinStack() {
        i_top=0;
    }
    
    void push(int val) {
        arr.push_front(val);
    }
    
    void pop() {
        arr.pop_front();
    }
    
    int top() {
        return arr.front();
    }
    
    int getMin() {
        return *min_element(arr.begin(),arr.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */