class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> negga,pos;
        for(int i =0;i<n;i++)
        {
            if(nums[i]<0) negga.emplace_back(nums[i]);
            else pos.emplace_back(nums[i]);
        }
        vector<int> Ans; 
        for(int i = 0;i<n/2;i++)
        {
            Ans.emplace_back(pos[i]);
            Ans.emplace_back(negga[i]);
        }
        return Ans;
    }
};