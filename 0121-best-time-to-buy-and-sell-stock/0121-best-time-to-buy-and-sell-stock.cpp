class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mx = INT_MIN;
        vector<int> mxnext(n,0);
        mxnext[n-1]= prices[n-1];
        for(int i =n-2;i>=0;i--)
        {
            mxnext[i]=max(prices[i],mxnext[i+1]);
        }
        for(int i =0;i<n-1;i++)
        {
            mx = max(mxnext[i+1]-prices[i],mx);
        }
        if(mx>0)return mx;
        else return 0;
    }
};