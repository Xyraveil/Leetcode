class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums = nums1;
        int i =0,j=0;
        int k =0;
        while(i<n && j<m && k<n+m)
        {
            if(nums[j]<=nums2[i])
            {
                nums1[k] = nums[j];
                k++;
                j++;
            } 
            else
            {
                nums1[k]=nums2[i];
                i++;
                k++;
            }
        }
        while(i<n && k<n+m)
        {
            nums1[k]=nums2[i];
            i++;
            k++;
        }
        while(j<m && k<n+m)
        {
            nums1[k] = nums[j];
            k++;
            j++;
        }
    }
};