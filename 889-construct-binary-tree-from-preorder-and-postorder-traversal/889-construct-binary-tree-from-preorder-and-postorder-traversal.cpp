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
    
    TreeNode* rec(int psi, int pei, int posi, int poei, vector<int>& pre, vector<int>& post){
        if(psi > pei){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[psi]);
        if(psi == pei){
            return root;
        }
        int index = posi;
        while(pre[psi + 1] != post[index]){
            index++;
        }
        int count = index - posi + 1;
        root->left = rec(psi + 1, psi + count, posi, index, pre, post);
        root->right = rec(psi + count + 1, pei, index + 1, poei - 1, pre, post);
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return rec(0, preorder.size()-1, 0, postorder.size()-1, preorder, postorder);
    }
};