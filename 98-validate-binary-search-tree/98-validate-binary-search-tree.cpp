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
    
    bool ans = true ; 
    
    void validate(TreeNode* root,  long int max, long int min)
    {
        if(root==NULL)
            return;
        
        if(root->val >= max || root->val<= min )
        {
            ans = false;
        }
        
        validate(root->left,root->val,min);
        validate(root->right,max,root->val);
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        validate(root,LONG_MAX,LONG_MIN);
        return ans;
    }
};