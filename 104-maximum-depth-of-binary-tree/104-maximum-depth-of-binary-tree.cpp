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
        
        if(root==NULL)
        {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while(!q.empty())
        {
            bool flag = false;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left!=NULL)
                {
                    q.push(cur->left);
                    flag=true;
                }
                if(cur->right!=NULL)
                {
                    q.push(cur->right);
                    flag = true;
                }
            }
            if(flag)
            {
                depth++;
            }
        }
        return depth;
    }
    
};