class Solution {
public:
    string losingPlayer(int x, int y) {
        int turns = min(x, y/4);
        if(turns%2 == 0){
            return "Bob";
        }
        return "Alice";
    }
};