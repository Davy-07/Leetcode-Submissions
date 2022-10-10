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
    int sum = 0;
    bool ans = false;
    
    void preorder(TreeNode* root, int target)
    {
        if(root==NULL)
            return;
        sum+=root->val;
        preorder(root->left,target);
        preorder(root->right,target);
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==target)
            ans = true;
        }
        sum-=root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        preorder(root,targetSum);
        return ans;
    }
};