class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>A;
        for(int i = 0;i<n;i++)
        {
            A.emplace_back(nums[i]);
        }
        sort(A.begin(),A.end());
        set<vector<int>> Ans1;
        vector<vector<int>> Ans;
        for(int i =0;i<n-2;i++)
        {
            int target = 0-A[i];
            int l = i+1;
            int r = n-1;
            while(l<r)
            {
                int sum = A[l]+A[r];
                if(sum==target) 
                {
                    Ans1.insert({A[i],A[l],A[r]});
                    l++;
                    r--;
                }
                else if(sum>target) r--;
                else l++;
            }
        }
        for(auto it:Ans1)
        {
            Ans.push_back(it);
        }
        return Ans;
    }
};