class Solution {
public:
    bool is_vowel(char c) {
    switch(c)
    {
        // check for capitalized forms as well.
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            
            return 1;
        default:
            return 0;
    }
}
    string sortVowels(string s) {
        vector<int> arr;
        priority_queue<int,vector<int> ,greater<int>> pq;
        for(int i=0;i<s.size();i++){
            if(is_vowel(s[i])){
                pq.push(s[i]-'0');
                arr.push_back(i);
            }
        }
        int ind=0;
        while(!pq.empty()){
            int i= arr[ind++];
            s[i] = pq.top()+'0';
            pq.pop();            
        }
        return s;
    }
};