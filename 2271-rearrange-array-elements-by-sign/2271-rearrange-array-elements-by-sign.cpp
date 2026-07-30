class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> negga,pos;
        int posind =0;
        int negind = 1;
        vector<int> Ans(n); 
        for(int i =0;i<n;i++)
        {
            if(nums[i]<0) 
            {
                Ans[negind] = nums[i];
                negind+=2;
            }
            else
            {
                Ans[posind] = nums[i];
                posind+=2;
            }
        }
        return Ans;
    }
};