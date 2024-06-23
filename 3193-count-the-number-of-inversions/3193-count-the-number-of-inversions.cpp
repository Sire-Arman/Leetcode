#define lli long long int
#define flp(a,b,i) for(int i=a;i<b;i++)
#define sz(a) a.size()
#define pi(a) pair<int,int> a
#define vi(a) vector<int> a
#define vin(a,n) vector<int> a(n)
#define vs(a) vector<string> a
#define vsn(a,n) vector<string> a(n)
#define vpi(a) vector<pair<int,int>> a
#define vpin(a,n) vector<pair<int,int>> a(n)
#define MOD 1000000007
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& req) {
        map<int,int> mp;
    for(auto it : req){
        mp[it[0]+1] = it[1];
        
    }
    lli perm [n+1][401];
        memset(perm,0,sizeof(perm));
    perm [0][0] = 1;

    flp(1,n+1,i){
        flp(0,401,j){
            flp(0,i,k){
                int prev = j - k;
                if(prev >= 0){
                    perm[i][j] = (perm[i][j] + perm[i-1][prev])%MOD;
                }
            }
        }
        if(mp.find(i) != mp.end()){
            long target = mp[i];
            flp(0,401,j){
                if(j != target){
                    perm[i][j] = 0;
                }
            }
        }
    }
        long res = 0;
        for(long long int it : perm[n]){
            res = (res + it)%MOD;
        }
        return (int)res;
    }
};