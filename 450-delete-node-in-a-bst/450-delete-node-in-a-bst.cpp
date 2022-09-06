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
    
    TreeNode* findLastRight(TreeNode* root)
    {
        if(root->right==NULL)
        {
            return root;
        }
        return findLastRight(root->right);
    }
    
    TreeNode* Delete(TreeNode* root)
    {
        if(root->left==NULL)
        {
            return root->right;
        }
        else if(root->right==NULL)
        {
            return root->left;
        }
        
    
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)
            return NULL;
        
        if(root->val==key)
        {
            return Delete(root);
        }
        
        TreeNode* temp = root;
        while(root!=NULL)
        {
            if(root->val>key)
            {
                if(root->left && root->left->val==key)
                {
                    root->left = Delete(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else if(root->val<key)
            {
                if(root->right && root->right->val==key)
                {
                    root->right = Delete(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
                
            }
        }
        return temp;
    }
};