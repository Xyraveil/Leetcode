class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int ind = -1;
        int min = INT_MAX;
        vector<int> ans;
        int i =0;
        while(i<nums.size())
        {
            if(abs(nums[i])<min)
            {
                ind = i;
                min = abs(nums[i]);
            }
            i++;
        }
        int left = ind,right = ind;
        
        while(left>=0 && right<nums.size())
        {
            if(left==right) 
            {
                ans.push_back(nums[left]*nums[left]);
                left--;
                right++;
                continue;
            }
            if(abs(nums[left])<=nums[right])
            {
                ans.push_back(nums[left]*nums[left]);
                left--;
            }
            else
            {
                ans.push_back(nums[right]*nums[right]);
                right++;
            }
        }
        while(left>=0)
        {
            ans.push_back(nums[left]*nums[left]);
            left--;
        }
        while(right<nums.size())
        {
            ans.push_back(nums[right]*nums[right]);
            right++;
        }
        return ans;
    }
};