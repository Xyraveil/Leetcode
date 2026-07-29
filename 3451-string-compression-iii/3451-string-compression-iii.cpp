class Solution {
public:
    string compressedString(string s) {
        int n = s.size();
        string comp = "";
        int ind = 0;
        int count =1;
        while(ind<n-1)
        {
            if(s[ind]==s[ind+1] && count<9)
            {
                ind++;
                count++;
            }
            else
            {
                comp += to_string(count);
                comp +=s[ind];
                ind++;
                count=1;
            }
        }
        comp += to_string(count);
        comp +=s[ind];
        return comp;
    }
};