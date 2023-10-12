/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray m, int length){
        int left =1;
        int right = length-2;
        while(left!=right){
            int mid = left + (right - left)/2;
            if(m.get(mid) < m.get(mid+1)){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
    int binarySearch(int target, MountainArray m, int st,int end){
        while(st!=end){
            int mid = st + (end-st)/2;
            if (m.get(mid) < target){
                   st = mid+1;
            }
            else{
                 end = mid;
            }  
        }
        return st;
    }
    int RevbinarySearch(int target, MountainArray m, int st,int end){
        while(st!=end){
            int mid = st + (end-st)/2;
             if (m.get(mid) > target){
                st = mid+1;
            }
            else{
                end = mid;
            }
        }
        return st;
    }
    int findInMountainArray(int target, MountainArray &m) {
        int length = m.length();
        int peak = findPeak( m, length);
        // cout<<peak<<" ";
        int res = binarySearch(target,m,0,peak);
        // cout<<res<<" ";
        if(m.get(res) == target){
            return res;
        } 
        res = RevbinarySearch(target,m,peak+1,length-1);
        cout<<res<<" ";
        if(m.get(res) == target){
            return res;
        } 
        return -1;
    }
};