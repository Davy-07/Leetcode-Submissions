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
    int max_sum = INT_MIN;
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int lh = max(0,height(root->left));
        int rh = max(0,height(root->right));
        
        max_sum = max(max_sum,lh+rh+root->val);
        return root->val + max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int s = height(root);
        return max_sum;
    }
};