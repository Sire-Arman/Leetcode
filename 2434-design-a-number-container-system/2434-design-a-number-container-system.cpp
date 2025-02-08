class NumberContainers {
public:
map<int,set<int>> mp;
map<int,int> idx;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(idx[index]){
            auto &a = mp[idx[index]];
            if(a.size()) {
                a.erase(index);
                }
        }
        idx[index] = number;
        mp[number].insert(index);
    }
    
    int find(int number) {
        if(mp[number].size()>0) return *mp[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */