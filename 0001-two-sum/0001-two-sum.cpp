class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
       map<int,vector<int>> ind;
       for(int i =0;i<nums.size();i++)
       {
            ind[nums[i]].emplace_back(i);
       }
       sort(nums.begin(),nums.end());
       int left = 0, right = nums.size()-1;
       while(left<right)
       {
            if(nums[left]+nums[right]==target)
            {
                if(nums[left]==nums[right]) return {ind[nums[left]][0],ind[nums[left]][1]};
                else
                {
                    return {ind[nums[left]][0],ind[nums[right]][0]};
                }
            }
            else if(nums[left]+nums[right]>target)
            {
                right--;
            }
            else left++;
       }
        return {0,0};
    }
};