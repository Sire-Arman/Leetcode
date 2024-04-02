class Solution {
public:
     vector<int> nextSmaller(vector<int>& heights , int n ){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for( int i = n-1;i>=0;i--){
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top() ] >= curr){
                s.pop();
            }
            ans[i] = (s.top());
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int>& heights , int n ){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for( int i = 0;i<n;i++){
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top() ] >= curr){
                s.pop();
            }
            ans[i] = (s.top());
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
      int area = INT_MIN;
      int n = heights.size();

      vector<int> prev(n);
      prev = prevSmaller(heights,n);

      vector<int> next(n);
      next = nextSmaller(heights , n);

      for( int i =0;i<n;i++){
          int l = heights[i];
          if(next[i] == -1){
              next[i] = n;
          }
          int b = next[i] - prev[i] - 1;
          int newArea = l*b;
          area = max( area , newArea);
      }
    return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<int> height(m,0);
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }
                else{
                    height[j] =0;
                }
            }
            ans = max(ans, largestRectangleArea(height));
        }
        return ans;
    }
};