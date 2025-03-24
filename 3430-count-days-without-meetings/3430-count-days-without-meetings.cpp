class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return vector<vector<int>>();
    }
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
 
    stack<vector<int>> mergedStack;
    mergedStack.push(intervals[0]);
 
    for (int i = 1; i < intervals.size(); i++) {
        vector<int> current = intervals[i];
        vector<int>& top = mergedStack.top();
 
        if (current[0] <= top[1]) {
            top[1] = max(top[1], current[1]);
        } else {
            mergedStack.push(current);
        }
    }
 
    vector<vector<int>> mergedIntervals;
    while (!mergedStack.empty()) {
        mergedIntervals.insert(mergedIntervals.begin(), mergedStack.top());
        mergedStack.pop();
    }
 
    return mergedIntervals;
}
    int countDays(int d, vector<vector<int>>& m) {
        vector<vector<int>> ans = overlappedInterval(m);
        sort(ans.begin(),ans.end());
        int ds =0;
        int ul = 0;
        for(auto it : ans){
            if(it[0] > ul){
                ds += it[0]-ul-1;
                ul = it[1];
            }
        }
        return ds + (d-ans[ans.size()-1][1]);
    }
};