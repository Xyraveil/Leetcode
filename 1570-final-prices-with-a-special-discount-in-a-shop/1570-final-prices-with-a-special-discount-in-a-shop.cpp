class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> disc(n,0);
        st.push(0);
        for(int i =n-1;i>=0;i--)
        {
            if(prices[i]>=st.top())
            {
                disc[i]=prices[i] - st.top();
                st.push(prices[i]);
                
            }
            else
            {
                while(!st.empty() && prices[i]<st.top())
                {
                    st.pop();
                }
                if(st.empty())disc[i]=0;
                else disc[i]=prices[i] - st.top();
                st.push(prices[i]);
                
            }
        }
        return disc;
    }
};