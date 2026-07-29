class Solution {
public:
    double myPow(double x, long long n) {
        
        double ans = 1;
        bool negga = n<0;
        n = abs(n);
        while(n>0)
        {
            long long power =1;
            double z = x;
            while(power*2<=n)
            {
                z = z*z;
                power = power*2;
            }
            n-=power;
            ans=ans*z;
        }
        if(negga) return 1/ans;
        return ans;
    }
};