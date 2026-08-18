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
    void asdf(TreeNode* root,vector<int> & mn)
    {
        if(!root) return;
        if(root->left)
        {         
            asdf(root->left,mn);
        }
        mn.emplace_back(root->val);
        if(root->right)
        {
            asdf(root->right,mn);
        }
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> A;
        asdf(root,A);
        int x = INT_MAX;
        for(int i =0;i<A.size()-1;i++)
        {
            x = min(x,A[i+1]-A[i]);
        }
        return x;
    }
};