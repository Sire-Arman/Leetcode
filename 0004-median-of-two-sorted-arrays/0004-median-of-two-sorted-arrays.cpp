class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int cnt=0;
        int n1 = nums1.size(),n2 = nums2.size();
        int i=0,j=0;
        int ind2 = (n1+n2)/2,ind1 = ((n1+n2)/2)-1;
        int el1=0,el2=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                 if(cnt == ind1){
                el1 = nums1[i];
            }
            if(cnt == ind2){
                el2=nums1[i];
            }
                cnt++;
                i++;
            }
            else {
                 if(cnt == ind1){
                el1 = nums2[j];
            }
            if(cnt == ind2){
                el2 = nums2[j];
            }
                cnt++;
               j++;
            }
        }
        while(i<n1){
              if(cnt== ind1){
                el1 = nums1[i];
            }
            if(cnt== ind2){
                el2 = nums1[i];
            }  
            cnt++;
            i++;
        }
        while(j<n2){
              if(cnt== ind1){
                el1 = nums2[j];
            }  
            if(cnt== ind2){
                el2 = nums2[j];
            }  
            j++;
            cnt++;
        }
        if((n1+n2)%2 ==0){
            return (el1 + el2)/2.0;
        }
        else return el2;
    }
};