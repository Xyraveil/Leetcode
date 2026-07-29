class Solution {
public:
    int reverseBits(int n) {
        int ans =0;
        for(int i =0;i<32;i++)
        {
            if(n%2==0)
            {
                ans<<=1;
            }
            else
            {
                ans<<=1;
                ans+=1;
            }
            n=n>>1;
        }
        return ans;
    }
};