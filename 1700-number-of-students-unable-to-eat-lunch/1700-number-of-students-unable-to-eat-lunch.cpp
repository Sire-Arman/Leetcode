class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& s) {
        int a =0,b=0;
        for(auto it : st){
            if(it) a++;
            else b++;
        }
        int rem = s.size();
        for(auto it : s){
            if(it && a == 0) break;
            if(!it && b ==0) break;
            if(it) {a--; rem--;}
            else {b--;rem--;}
        }
        return rem;
    }
};