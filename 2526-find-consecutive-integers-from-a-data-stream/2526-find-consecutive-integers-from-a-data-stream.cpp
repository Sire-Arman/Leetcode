class DataStream {
public:
    int cnt;
    int k;
    int value;
    DataStream(int value, int k) {
        // arr.push_back(value);
        cnt=0;
        this->k = k;
        this->value = value;
    }
    
    bool consec(int num) {
        if(num == value) cnt++;
        else cnt =0;
        return cnt >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */