class Solution {
public:
    int solve(vector<int>& c, int k){
         sort(c.begin(), c.end());
            if(c[0]>k)return 0;
        long long n = c.size();
        long long pts = 0;
         
        long long index = n-1;
        long long i = 0;
        
        while(i<=index){
              pts+=k/c[i];
              k=k%c[i];
              k+=c[index--];
            
        }
        return pts; 
    }
    int solve2(vector<int>& clr, int c){
         // Initialize variables
    vector<int> groups;
    int lastclr = clr[0];
    int currentGroup = 1;
    bool isSame = false;
    
    // Iterate through the array
    for (size_t i = 1; i < clr.size(); ++i) {
        if (clr[i] == lastclr) {
            groups.push_back(currentGroup);
            currentGroup = 1;
            isSame = true;
        } else {
            currentGroup++;
        }
        lastclr = clr[i];
    }
    groups.push_back(currentGroup);
    
    // Handle special cases
    if (groups.size() == 1 && groups[0] == clr.size() && clr[0] != clr[clr.size() - 1] && !isSame) {
        return clr.size();
    }
    
    if (clr[0] != clr[clr.size() - 1] && groups.size() > 1) {
        int lastGroup = groups.back();
        groups.pop_back();
        groups[0] += lastGroup;
    }
    
    // Calculate the result
    long result = 0;
    for (int group : groups) {
        result += std::max(0, group - (c - 1));
    }
    
    return static_cast<int>(result);
    }
    int numberOfAlternatingGroups(vector<int>& c, int k) {
        // c.push_back(c[0]);
        // reverse(c.begin(),c.end());
        // c.push_back(c[1]);  
        // reverse(c.begin(),c.end());
        int abc= k;
        int n = c.size();
        int i= 1;
        int ans =0;
        int len =0;
        vector<int> lng;
        
        int l=0,r=0,ind=1;
        int curr =0;
        while(ind <curr){
            if(c[ind] != c[r]){
                r++;
            }
            else{
                int l = r-l+1;
                if(l >=k) len += l-k+1;
            }
            ind = (ind+1)%n;
        }
        while(i<n-1){
            if(c[i] != c[i-1] && c[i] != c[i+1]){
                if(len == 0) len += 3;
                else len++;
            }
            else {
                if(len >= k){
                    ans += len-k+1;
                }
                lng.push_back(len);
                len = 0;
            }
            i++;
            lng.push_back(len);
            // cout<<len<<' ';
        }
        if(len >= k){
                    ans += len-k+1;
                }
        // cout<<endl;
        if(lng.size()>2 &&  (lng[0] < k || lng.back()< k) && lng[0]+lng.back() >= k){
            ans += (lng[0]+lng.back())-k;
        }
        // return ans;
        return solve2(c,abc);

    }
};