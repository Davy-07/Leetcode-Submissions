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
    bool ans  = true;
    
    void check(TreeNode* p,TreeNode* q)
    {
        if(p==NULL || q==NULL)
        {
            if(p==NULL && q==NULL)
            {
                return;
            }
            else{
                ans = false;
                return;
            }
        }
        
        if(p->val != q->val)
        {
            ans = false;
            return;
        }
        
        check(p->left ,q->right);
        check(p->right, q->left);
        
    }
    
    bool isSymmetric(TreeNode* root) {
        check(root->left, root->right);
        return ans;
    }
};