class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mxpr = 0;
        int sellday =1;
        int buy = prices[0];
        for(int i =0;i<n;i++)
        {
            if(prices[i]<buy)
            {
                buy = prices[i];
            }
            else if(prices[i]-buy>mxpr)
            {
                mxpr = prices[i]-buy;

            }
        }
        return mxpr;
    }
};