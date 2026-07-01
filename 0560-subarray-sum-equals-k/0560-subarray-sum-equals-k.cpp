class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int n = nums.size();
        vector<int> Pref(n);
        Pref[0]=nums[0];
        for(int i= 1;i<n;i++)
        {
            Pref[i]=Pref[i-1]+nums[i];
        }
        unordered_map<int,int> M;
        M[0]=1;        
        for(int i= 0;i<n;i++)
        {
            ans+=M[Pref[i]-k];
            M[Pref[i]]++;
        }
        return ans;
    }
};