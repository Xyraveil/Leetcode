class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n = nums.size();
       vector<pair<int,int>> A;
       for(int i = 0;i<n;i++)
       {
            A.emplace_back(nums[i],i);
       }
       sort(A.begin(),A.end());
       
       int l = 0,r=n-1;
       while(l<r)
       {
            int sum = A[l].first+A[r].first;
            if(sum==target) return {A[l].second,A[r].second};
            else if(sum>target) r--;
            else l++;
       }
       return {};
    }
};