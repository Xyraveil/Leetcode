class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long ans = 0;
        int negga = 1;
        int i =0;
        while( i<n && s[i]==' ') i++;
        if(i==s.size()) return 0;
        if(s[i]=='-')
        {
            negga = -1;
            i++;
        }
        else if(s[i]=='+')
        {
            i++;
        }

        while(i<n && isdigit(s[i]))
        {
            ans = ans*10 + (s[i]-'0');

            if(negga*ans >INT_MAX) return INT_MAX;
            if(negga*ans <INT_MIN) return INT_MIN;
            i++;
        }
        return (int)(negga*ans);
    }
};