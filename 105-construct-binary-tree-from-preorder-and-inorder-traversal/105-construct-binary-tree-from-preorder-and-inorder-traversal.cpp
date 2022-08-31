class Solution {
public:
    TreeNode * newnode(int val){
        TreeNode* temp=new TreeNode();
        temp->val=val;
        temp->left=temp->right=0;
        return temp;
    }
    TreeNode* constructTree(vector<int>&in,vector<int>&pre,int l, int r , unordered_map<int,int>&mp,int*preIndex){
        if(l>r) return NULL;
        TreeNode* root=newnode(pre[*preIndex]);
        (*preIndex)++;
        if(l==r) return root;
        int in_index=mp[root->val];
        root->left=constructTree(in,pre,l,in_index-1,mp,preIndex);
        root->right=constructTree(in,pre,in_index+1,r,mp,preIndex);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder) {
        unordered_map<int,int>mp;
        int size=inorder.size();
        for(int i=0;i<size;i++){      //O(N)
            mp[inorder[i]]=i;
        }
        int preIndex=0;
        TreeNode* root=constructTree(inorder,preorder,0,size-1,mp,&preIndex);
        return root;
    }
};