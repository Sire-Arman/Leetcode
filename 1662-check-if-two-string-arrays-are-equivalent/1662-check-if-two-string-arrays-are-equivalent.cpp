class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2){
        int i=0,j=0,k=0,l=0;
        while(i<w1.size() && j<w2.size()){
            if(w1[i][k++]!= w2[j][l++]){
                return false;
            }
            if(k==w1[i].size()){
                k=0;
                i++;
            }
            if(l==w2[j].size()){
                l=0;
                j++;
            }
        }
        if(j<w2.size() || i<w1.size()){
            return false;
        }
        return true;
    }
};