class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int bal = 0;
        int mini =0;
        int x = min(n,m);
        pair<int,int> totalfreq ={0,0};
        vector<pair<int,int>> row(n,{0,0});
        vector<pair<int,int>> col(m,{0,0});
        vector<pair<int,int>> diag(x,{0,0});
        // cout<<totalfreq.first<<' '<<totalfreq.second<<endl;
        for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(grid[i][j] =='X'){
                     row[i].first++;
                     col[j].first++;
                     if(i==j) diag[i].first++;
                 }
                 else if (grid[i][j] == 'Y'){
                      row[i].second++;
                     col[j].second++;
                     if(i==j) diag[i].second++;
                 }
             }
        }
        int res =0;
        for(int i=0;i<n;i++){
            if(grid[i][0] != '.') mini++;
                if(grid[i][0]=='X'){
                    bal++;
                }
            else if (grid[i][0] == 'Y') bal--;
            if(mini>=1 && bal == 0){
                res++;
            }
            
            totalfreq.first += row[i].first;
            totalfreq.second += row[i].second;
            // cout<<row[i].first<<' '<<row[i].second<<'-';
        }
        // cout<<endl;
        
        bal=0;
        mini=0;
        for(int j=0;j<m;j++){
            if(grid[0][j] != '.') mini++;
            if(grid[0][j]=='X'){
                    bal++;
                }
            else if (grid[0][j] == 'Y') bal--;
            if(mini>=1 && bal ==0){
                res++;
            }
            totalfreq.second += col[j].second;
            // cout<<col[j].first<<' '<<col[j].second<<'-';
            totalfreq.first += col[j].first;
        }
       // cout<<totalfreq.first<<' '<<totalfreq.second<<endl;
        totalfreq.first = totalfreq.first/2;
        totalfreq.second = totalfreq.second/2;
        for(int i=x-1;i>=1;i--){
            int r = n - (n-i-1); 
            if(r<n){
                totalfreq.first -= row[r].first;
                totalfreq.second -= row[r].second;
            }
            int c = m - (m-i-1);
            if(c<m){
                totalfreq.first -= col[c].first;
                totalfreq.second -= col[c].second;
            }
            // cout<<r<<' '<<c<<endl;
            if(r<n && c<m){
                totalfreq.first += diag[c].first;
                totalfreq.second += diag[c].second;
            }
           // cout<<totalfreq.first<<' '<<totalfreq.second<<endl;
            if(totalfreq.first == totalfreq.second && totalfreq.first>=1) res++;
        }
         int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> rowcolX(rows + 1, vector<int>(cols + 1, 0));
        vector<vector<int>> rowcolY(rows + 1, vector<int>(cols + 1, 0));

        // int rows = grid.size();
        // int cols = grid[0].size();
        
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                rowcolX[i][j] = rowcolX[i-1][j] + rowcolX[i][j-1] - rowcolX[i-1][j-1] + (grid[i-1][j-1] == 'X' ? 1 : 0);
                rowcolY[i][j] = rowcolY[i-1][j] + rowcolY[i][j-1] - rowcolY[i-1][j-1] + (grid[i-1][j-1] == 'Y' ? 1 : 0);
            }
        }
        
        //
        int ans = 0;
        
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                int X = rowcolX[i][j];
                int Y = rowcolY[i][j];
                char ch = grid[0][0];
                if (X == Y && X > 0 && (ch == 'X' || ch == 'Y' || ch == '.')) {
                    ++ans;
                }
            }
        }
        
        return ans;
        // cout<<"x"<<endl;
        // return ans;
        
    }
};