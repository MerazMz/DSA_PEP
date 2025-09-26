class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> result(m+n);
        int i=0,j=0,k=0;

        while(i<m and j<n){
            if(nums1[i]<nums2[j]){
                result[k]=nums1[i++];
            }else{
                result[k]=nums2[j++];
            }
            k++;
        }
        while(i<m or j<n){
            if(i<m){
                result[k]=nums1[i++];
            }else{
                result[k]=nums2[j++];
            }
            k++;
        }
        double ans;
        int size=result.size();
        int mid= size/2;
        if(size%2!=0){
            ans=result[mid];
        }else{
            ans=(result[mid]+result[mid-1])/2.0;
        }
        return ans;

    }
};