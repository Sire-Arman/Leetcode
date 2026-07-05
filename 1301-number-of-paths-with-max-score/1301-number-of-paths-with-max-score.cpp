class Solution {
public:
int dx[3] = {-1,0,-1};
int dy[3] = {0,-1,-1};
int MOD = 1e9+7;
map<pair<int,int>, pair<int,int>> memo;
   pair<int,int> solve_rec(vector<string>& b, int i, int j){
        if(i==0 && j ==0){
            return {0,1}; //score,count
        }
        if(memo.find({i,j}) != memo.end()) return memo[{i,j}];
        int bestScore = -1, bestCount = 0;

        for(int k =0;k<3;k++){
            int ni = i+dx[k],nj = j+dy[k];
            if(ni>=0 && nj >=0 && b[ni][nj] !='X'){
            auto [s,c] = solve_rec(b,ni,nj);
            if(s == -1) continue;
            if(s > bestScore){
                bestScore = s;
                bestCount = c;
            }
            else if (s == bestScore){
                bestCount = (bestCount+c)%MOD;
            }
            }
        }
        if(bestScore != -1 && isdigit(b[i][j])){
            bestScore = (bestScore+(b[i][j]-'0'))%MOD;
        }
        return memo[{i,j}] = {bestScore,bestCount};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        auto [score,count] = solve_rec(board,n-1,n-1);
        if(score == -1) return {0,0};
        return {score , count%MOD};
    }
};