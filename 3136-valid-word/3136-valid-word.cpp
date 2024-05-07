class Solution {
public:
    bool isValid(string word) {
        if(word.size() <3 ) return 0;
        int l=0,u=0,d=0,v=0,c=0;
        for(auto it: word){
            if(it == '#' || it == '$' ||it == '@') return false;
            if(isupper(it)) u++;
            if(islower(it)) l++;
             if(isdigit(it)) d++;
             else if(it == 'a'||it == 'e'||it == 'i'||it == 'o'||it == 'u' ||it == 'A'||it == 'E'||it == 'I'||it == 'O'||it == 'U') v++;
             else c++;
        }
        return (l||u||d)&&c&&v;
    }
};