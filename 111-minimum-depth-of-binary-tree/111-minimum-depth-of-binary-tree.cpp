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
    int minDepth(TreeNode* root) {
        
        if(root==NULL)
        {
            return 0;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while(!q.empty())
        {
            int size = q.size();
            bool not_null = false;
            bool both_null = false;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left==NULL && cur->right==NULL)
                {
                    both_null = true;
                    not_null = false;
                    break;
                }
                if(cur->left!=NULL)
                {
                    q.push(cur->left);
                    not_null = true;
                }
                if(cur->right!=NULL)
                {
                    q.push(cur->right);
                    not_null = true;
                }
            }
            if(not_null)
            {
                depth++;
            }
            if(both_null)
            {
                break;
            }
        }
        return depth;
    }
};