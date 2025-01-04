class TaskManager {
private:
   unordered_map<int,pair<int,int>> tm;
   set<pair<int,int>,greater<pair<int,int>>> pq;
public:    
   TaskManager(vector<vector<int>>& tasks) {
       for(const auto& t : tasks) {
           tm[t[1]] = {t[2],t[0]};  
           pq.insert({t[2],t[1]});
       }
   }
   
   void add(int uid, int tid, int p) {
       tm[tid] = {p,uid};
       pq.insert({p,tid}); 
   }
   
   void edit(int tid, int np) {
       int op = tm[tid].first;
       pq.erase({op,tid});
       tm[tid].first = np;
       pq.insert({np,tid});
   }
   
   void rmv(int tid) {
       int p = tm[tid].first;
       pq.erase({p,tid});
       tm.erase(tid);
   }
   
   int execTop() {
       if(pq.empty()) return -1;
       
       auto tt = *pq.begin();
       int tid = tt.second;
       int uid = tm[tid].second;
       
       pq.erase(pq.begin());
       tm.erase(tid);
       
       return uid;
   }
};