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
    int good_nodes = 0;
    void count(TreeNode* root,int curMax)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->val>=curMax)
        {
            curMax = root->val;
            good_nodes ++;
        }
        
        count(root->left,curMax);
        count(root->right,curMax);
    }
    
    int goodNodes(TreeNode* root) {
            
            count(root,root->val);
            return good_nodes;
    }
};