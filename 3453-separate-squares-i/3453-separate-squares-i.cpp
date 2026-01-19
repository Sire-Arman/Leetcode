class Solution {
public:

    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }

    double calculate_area(vector<vector<int>>& s, double y_limit){
        double running_area = 0.00000;
        for(auto& it : s){
            double x = it[0], y = it[1], len = it[2];
            if(y>=y_limit){break;}

            if(y+len>y_limit){
                double h = y_limit - y;
                running_area += (double)len*h;
            }
            else{running_area += (double)len*len;}
            // cout<<running_area<<endl;
        }
        return running_area;
    }
    double binarySearch(vector<vector<int>>& s,double& y_max, double& y_min, double& req ){
        double running_area = 0.00000;
        double ans = 0.00000;
        double mid = 0.00000;
        double eps = 1e-5;

        while((y_max-y_min)>eps){
            mid = (y_max+y_min)/2.00000;
            running_area = calculate_area(s,mid);
            if(running_area < req){
                y_min = mid;
            }
            else{
                y_max = mid;
            }
        }
        return y_min;
    }
    double separateSquares(vector<vector<int>>& s) {
        double y_min = INT_MAX*1.00000,y_max = 0.00000;
        double total_area = 0.00000;

        sort(s.begin(),s.end(), cmp);

        for(auto& it: s){
            total_area += double(it[2])*it[2];
            if(it[1]<y_min){
                y_min = double(it[1]);
            }
            if((it[1]+it[2])>y_max){
                y_max = double(it[1]+it[2]);
            }
        } 
        double req = total_area/2.00000;
        return binarySearch(s,y_max,y_min,req);
        
    }
};