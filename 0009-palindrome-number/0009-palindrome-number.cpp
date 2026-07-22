class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string ass = s;
        reverse(ass.begin(),ass.end());
        if(ass==s) return true;
        else return false;
        
    }
};