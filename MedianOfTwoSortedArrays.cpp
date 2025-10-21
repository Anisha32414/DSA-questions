class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        int ele2ind = n/2;
        int ele1ind = ele2ind - 1;
        int ele1val=-1;
        int ele2val=-1;
        int cnt=0;
        while(i<n1 && j<n2){
            if( nums1[i]<nums2[j]){
                if(cnt==ele1ind) ele1val=nums1[i];
                if(cnt==ele2ind) ele2val=nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt==ele1ind) ele1val=nums2[j];
                if(cnt==ele2ind) ele2val=nums2[j];
                cnt++;
                j++;
            }
        }
        while(i<n1){
            if(cnt==ele1ind) ele1val=nums1[i];
            if(cnt==ele2ind) ele2val=nums1[i];
            cnt++;
            i++;
        }
        while(j<n2){
            if(cnt==ele1ind) ele1val=nums2[j];
            if(cnt==ele2ind) ele2val=nums2[j];
            cnt++;
            j++;
        }

        if(n%2==1) return ele2val;
        return (double)(double(ele2val+ele1val))/2.0;
    }
};
