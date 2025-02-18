class Solution {
public:
bool check(string &a, string &b){
    for(int i=0;i<b.size();i++){
        if(b[i]=='I'){
            if(a[i]>a[i+1]) return false;
        }
        else if (b[i]=='D'){
            if(a[i]<a[i+1]) return false;
        }
    }
    return true;
}
    string smallestNumber(string pattern) {
        string seq = "";
        for(int i = 1 ;i<= pattern.size()+1;i++){
            seq.push_back(i+'0');
        }
        string per=seq;
        while(!check(per,pattern)){
            next_permutation(per.begin(),per.end());
        }
        return per;
    }
};