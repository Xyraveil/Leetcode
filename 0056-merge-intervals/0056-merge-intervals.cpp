class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> A(1e4 +1,0);
        vector<vector<int>> ans;
        int cnt =0;
        sort(intervals.begin(),intervals.end());
        for(auto it:intervals)
        {
            int start = it[0];
            int end = it[1];
            if(start == end)
            {
                if(A[start]!=0) continue;
                A[start]= INT_MAX;
                continue;
            }
            if(A[start]==INT_MAX) A[start]=1;
            else A[start]++;
            if(A[end]==INT_MAX) A[end]=-1;
            else A[end]--;
        }
        int pref =0;
        int start=-1,end=-1;
        for(int i = 0;i<1e4+1;i++)
        {
            int prev = pref;
            if(A[i]==INT_MAX)
            {
                if(start>=0 && end<0) continue;
                else 
                {
                    ans.push_back({i,i});
                    continue;
                }
            }
            pref = pref+A[i];
            if(prev ==0 && pref>0)    
            {
                start = i;
            }
            else if(prev>0 && pref==0)
            {
                end = i;
                ans.push_back({start,end});
                start = end =-1;
            }
        }
        return ans;
    }
};