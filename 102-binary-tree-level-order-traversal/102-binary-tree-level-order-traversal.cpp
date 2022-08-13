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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left!=NULL)
                {
                    q.push(cur->left);
                }
                if(cur->right!=NULL)
                {
                    q.push(cur->right);
                }
                
                temp.push_back(cur->val);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};