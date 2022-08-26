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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
        {
            return 0;
        }
        int max_size = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int left,right;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* cur = q.front().first;
                long int pos = q.front().second;
                q.pop();
                if(i==0)
                {
                    left = pos;
                }
                if(i==size-1)
                {
                    right = pos;
                }
                if(cur->left)
                {
                    q.push({cur->left,2*pos+1});
                }
                if(cur->right)
                {
                    q.push({cur->right,2*pos+2});
                }
            }
            
            max_size = max(max_size,right-left+1);        
                
        }
        return max_size;
    }
};