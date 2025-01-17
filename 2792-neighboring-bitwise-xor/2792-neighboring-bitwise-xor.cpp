class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int n=d.size();
        bool st=0,curr =0;
        bool next = 0;
        bool ans = true;
        for(int i=0;i<n;i++){
            if(d[i]==1){
                next = !curr;
            }
            else{
                next = curr;
            }
            curr = next;
        }
        if(st != curr) ans = false;

        return ans;
    }
};