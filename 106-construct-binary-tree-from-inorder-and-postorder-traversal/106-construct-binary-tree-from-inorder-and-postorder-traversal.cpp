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
    
    TreeNode* constructTree(vector<int>&postorder,unordered_map<int,int>&mp, int start, int end, int &postIdx)
{
    if(start > end) return NULL;
    TreeNode* root = new TreeNode(postorder[postIdx]);
    
    int curIdx = mp[postorder[postIdx]];
    postIdx--;
    
    root->right = constructTree(postorder,mp,curIdx+1,end,postIdx);
    root->left = constructTree(postorder,mp,start,curIdx-1,postIdx);
    
    return root;
}
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
    for(int i=0; i<inorder.size(); i++){
        mp[inorder[i]] = i;
    }
    int postIdx = postorder.size()-1;
    return constructTree(postorder,mp,0,inorder.size()-1, postIdx);
    }
};