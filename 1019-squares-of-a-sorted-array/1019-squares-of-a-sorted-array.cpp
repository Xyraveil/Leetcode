class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int ind =0;
        vector<int> ans;
        while(ind<nums.size()-1)
        {
            if(abs(nums[ind])<abs(nums[ind+1]))
            {
                break;   
            }
            ind++;

        }

        int left = ind,right = ind;
        ans.emplace_back(nums[left]*nums[left]);
        left--;
        right++;
        while(left>=0 && right<nums.size())
        {
            if(abs(nums[left])<=nums[right])
            {
                ans.emplace_back(nums[left]*nums[left]);
                left--;
            }
            else
            {
                ans.emplace_back(nums[right]*nums[right]);
                right++;
            }
        }
        while(left>=0)
        {
            ans.emplace_back(nums[left]*nums[left]);
            left--;
        }
        while(right<nums.size())
        {
            ans.emplace_back(nums[right]*nums[right]);
            right++;
        }
        return ans;
    }
};