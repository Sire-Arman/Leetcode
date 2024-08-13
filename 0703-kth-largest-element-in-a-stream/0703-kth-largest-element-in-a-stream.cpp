class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int k;
    int value=INT_MAX;
    KthLargest(int v, vector<int>& nums) {
        k=v;
         for (int num : nums) {
            if (minHeap.size() < k) {
                minHeap.push(num);
            } else if (num > minHeap.top()) {
                minHeap.push(num);
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
        }
    }
    
    int add(int val) {
        
        if (minHeap.size() < k) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.push(val);
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */