class Solution {
public:
    string reversePrefix(string word, char ch) {
        int ind = word.size();
        for(int i=0;i<word.size();i++){
            if(ch == word[i]) {ind = i; break;}
        }
        int i=0;
        if(ind != word.size())
        while(i<ind){
            swap(word[i],word[ind]);
            i++;
            ind--;
        }
        return word;
    }
};