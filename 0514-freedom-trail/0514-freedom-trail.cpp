class Solution {
public:
    int helper(int in_index, int pos, unordered_map<char, vector<int>>& positions, string& key, string& ring, vector<vector<int>>& memo) {
        if (in_index == key.size()) {
            return 0;
        }
        if (memo[in_index][pos] != -1) {
            return memo[in_index][pos];
        }
        int min_steps = INT_MAX;
        for (int i : positions[key[in_index]]) {
            int steps;
            if (i >= pos) {
                steps = min(i - pos, static_cast<int>(pos + ring.size()) - i);
            } else {
                steps = min(pos - i, static_cast<int>(i + ring.size()) - pos);
            }
            int next_steps = helper(in_index + 1, i, positions, key, ring, memo);
            min_steps = min(min_steps, steps + next_steps);
        }
        memo[in_index][pos] = min_steps + 1;
        return min_steps + 1;
    }
    int findRotateSteps(string ring, string key) {
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<ring.size();i++){
            mp[ring[i]].push_back(i);
        }
        vector<vector<int>> dp(101,vector<int>(101,-1));
        return helper(0,0,mp,key,ring,dp);
    }
};