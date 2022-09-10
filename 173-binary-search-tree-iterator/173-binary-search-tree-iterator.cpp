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
class BSTIterator {
public:
    
    vector<int> inorder;
    int it;
    void in(TreeNode* root)
    {
        if(root==NULL)
            return;
        in(root->left);
        inorder.push_back(root->val);
        in(root->right);
    }
    BSTIterator(TreeNode* root) {
        in(root);
        it = -1;
    }
    
    int next() {
        it++;
        return inorder[it];
    }
    
    bool hasNext() {
        
        int temp = it;
        if(++temp!=inorder.size())
            return true;
        else
            return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */