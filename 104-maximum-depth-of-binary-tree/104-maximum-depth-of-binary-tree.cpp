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
    int maxDepth(TreeNode* root) {
        /*We can devise a recurence relation for height as 1 + max(height of left subtree,                 height of right subtree)*/
        if(root==NULL)
        {
            return 0;
        }
        int max_left = maxDepth(root->left);
        int max_right = maxDepth(root->right);
        return (1+ max(max_left,max_right));
    }
    
};