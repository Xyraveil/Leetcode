class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;
        int ind = n-1;
        while(ind > 0 && nums[ind-1]>=nums[ind])
        {
            ind--;
        }
        if(ind==0) 
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i =n-1;i>=ind;i--)
        {
            if(nums[ind-1]<nums[i])
            {
                swap(nums[ind-1],nums[i]);
                break;
            }
        }
        
        reverse(nums.begin()+ind,nums.end());
        return;
    }
};