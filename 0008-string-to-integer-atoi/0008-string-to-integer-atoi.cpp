class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long ans = 0;
        bool negga = false;
        int len = 0;
        int ind = 0;
        for (auto c : s) {
            if (c - '0' >= 0 && c - '0' <= 9) {
                break;
            } else if (c == '-') {
                negga = true;
                ind++;
                break;
            } else if (c == '+') {
                ind++;
                break;
            } else if (c == ' ') {
                ind++;
                continue;
            }
        }
        for (int i = ind; i < n; i++) {
            char c = s[i];
            if (c - '0' >= 0 && c - '0' <= 9) {
                if (len == 10 || ans/10 > INT_MAX / 10) {
                    if (negga)
                        return INT_MIN;
                    else
                        return INT_MAX;
                }
                else if(ans/10 == INT_MAX / 10)
                {
                    if(c-'0'>=7) 
                    {
                        if(negga) 
                        if(c-'0'>=8) return INT_MIN;
                        else return -INT_MAX;

                        else return INT_MAX;
                    }
                }
                ans += c - '0';
                ans *= 10;
                if (ans > 0)
                    len++;
            } else {
                break;
            }
        }
        ans /= 10;
        if (negga)
            ans *= -1;
        return ans;
    }
};