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
    int preIndex = 0;
    TreeNode* bst(vector<int>& preorder, int bound)
    {
        if(preIndex == preorder.size() || preorder[preIndex]>bound)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;
        root->left = bst(preorder,root->val);
        root->right = bst(preorder,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return bst(preorder,INT_MAX);
        
        
    }
};