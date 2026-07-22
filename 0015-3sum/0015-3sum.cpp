class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        int n = A.size();

        sort(A.begin(),A.end());
        vector<vector<int>> Ans;
        for(int i =0;i<n-2 && A[i]<=0;i++)
        {   
            if(i > 0 && A[i] == A[i-1])
                continue;
            int l = i+1;
            int r = n-1;
            while(l<r)
            {
                int sum = A[l]+A[r]+A[i];
                if(sum==0) 
                {
                    Ans.push_back({A[i],A[l],A[r]});
                    l++;
                    r--;
                    while(l<r && A[l]==A[l-1])l++;
                    while(l<r && A[r]==A[r+1])r--;
                }
                else if(sum>0) r--;
                else l++;
            }
        }
        return Ans;
    }
};