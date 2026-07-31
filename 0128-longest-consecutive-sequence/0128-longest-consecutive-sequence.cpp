class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        // vector<int> vis(n,0);
        // int mxlen = INT_MIN;
        // map<int,stack<int>> M;
        // for(int i = 0;i<n;i++)
        // {
        //     M[nums[i]].push(i);
        // }
        // for(int i = 0;i<n;i++)
        // {
        //     if(vis[i]==0)
        //     {
        //         int high = nums[i]+1;
        //         int low = nums[i]-1;
        //         while(!M[high].empty())
        //         {
        //             vis[M[high].top()] =1;
        //             M[high].pop();
        //             high++;
                    
        //         }
        //         while(!M[low].empty())
        //         {
        //             vis[M[low].top()] =1;
        //             M[low].pop();
        //             low--;
        //         }
        //         mxlen = max(mxlen, high - low -1 );
        //     }
        // }
        // if(mxlen<0) return 0;
        // return mxlen;
        set<int> S;
        for(int i =0;i<n;i++)
        {
            S.insert(nums[i]);
        }
        int mxlen =0;
        
        for(int i: S)
        {
            if(S.find(i-1)==S.end()) 
            {
                int count =1;
                int j = i;
                while(S.find(j+1)!=S.end())
                {
                    count++;
                    j++;
                }
                mxlen = max(mxlen, count);
            }
        }
        return mxlen;
    }
};