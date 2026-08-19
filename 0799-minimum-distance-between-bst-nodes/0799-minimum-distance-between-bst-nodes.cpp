/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void asdf(TreeNode* root,int& prev,int&mn)
    {
        if(!root) return;      

        asdf(root->left,prev,mn);
        if(prev!=INT_MIN)
        mn = min(mn,(root->val)-prev);
        prev = root->val;
        asdf(root->right,prev,mn);
        
    }
    int minDiffInBST(TreeNode* root) {
        int prev = INT_MIN;
        int mn = INT_MAX;
        asdf(root,prev,mn);
        return mn;
    }
};