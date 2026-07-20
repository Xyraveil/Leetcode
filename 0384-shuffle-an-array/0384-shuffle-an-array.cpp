class Solution {
    private:
    int randi(int n)
    {
        return rand()%n;
    }
public:
    vector<int> og;
    Solution(vector<int>& nums) {
        og = nums;
    }
    
    vector<int> reset() {
        return og;
    }
    
    vector<int> shuffle() {
        int n = og.size();
        vector<int> temp(n);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            int j = randi(n);
            while(vis[j])
            {
                j = randi(n);
            }
            vis[j]=1;
            temp[i]=og[j];
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */