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
    TreeNode* asdf(int start,int end, int& ind, vector<int>& pre)
    {
        if(ind== pre.size() || pre[ind]>end || start>pre[ind]) return nullptr;
        int nxt = pre[ind++];
        TreeNode* root = new TreeNode(nxt);
        root->left =  asdf(start,nxt,ind,pre);
        root->right =  asdf(nxt,end,ind,pre);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // vector<int> inorder=preorder;
        // sort(inorder.begin(),inorder.end());
        // TreeNode* root = new TreeNode(preorder[0]);
        // int n = preorder.size();
        // for(int i =1;i<n;i++)
        // {
        //     int x = preorder[i];
        //     TreeNode*curr = root;
        //     while(true)
        //     {
        //         if(curr->val < x)
        //         {
        //             if(curr->right)
        //             {
        //                 curr = curr->right;
        //             }
        //             else
        //             {
        //                 curr->right = new TreeNode(x);
        //                 break;
        //             }
        //         }
        //         else
        //         {
        //             if(curr->left)
        //             {
        //                 curr = curr->left;
        //             }
        //             else 
        //             {
        //                 curr->left = new TreeNode(x);
        //                 break;
        //             }
        //         }
        //     }
            
        // }
        // return root;
        TreeNode* head = new TreeNode(preorder[0]);
        int ind = 0;
        return asdf(INT_MIN,INT_MAX,ind,preorder);
    }
};