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
    int findPeak(MountainArray m,int length){
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
    int binarySearch(int target, MountainArray m, int st,int end,bool reverse){
        while(st!=end){
            int mid = st + (end-st)/2;
            if(!reverse){
                if (m.get(mid) > target){
                st = mid+1;
            }
            else{
                end = mid;
            }
        }
            else{
                  if (m.get(mid) < target){
                   st = mid+1;
            }
            else{
                 end = mid;
            }  
                }    
        }
        return st;
    }
    // int RevbinarySearch(int target, MountainArray m, int st,int end){
    //     while(st!=end){
    //         int mid = st + (end-st)/2;
    //         if (m.get(mid) < target){
    //             end = mid;
    //         }
    //         else{
    //             st = mid+1;
    //         }
    //     }
    //     return st;
    // }
    int findInMountainArray(int target, MountainArray &m) {
        int length = m.length();
        int peak = findPeak( m, length);
        int inc = binarySearch(target , m, 0,peak,true);
        if(m.get(inc) == target){
            return inc;
        }
            int dec = binarySearch(target , m, peak+1,length-1,false);
        if(m.get(dec) == target){
            return dec;
        }
        return -1;
    }
};