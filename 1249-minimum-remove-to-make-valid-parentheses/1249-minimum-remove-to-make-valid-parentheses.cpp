class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> str, prev;
        for(int i =0;i<s.size();i++){
            if(s[i] == '('){
                prev.push({'(',i});
                str.push({'(',i});
            }
            else if(s[i] == ')'){
                if(!prev.empty() && prev.top().first == '('){
                    prev.pop();
                    str.push({')',i});
                }
            }
            else{
                str.push({s[i],i});
            }
        }
        string temp = "";
        while(!prev.empty()){
            if(prev.top().second != str.top().second){
                temp += str.top().first;
            }
            else{
                prev.pop();
            }
            str.pop();
        }
        while(!str.empty()){
            temp += str.top().first;
            str.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};