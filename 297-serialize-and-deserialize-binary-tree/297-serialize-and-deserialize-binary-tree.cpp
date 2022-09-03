/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root==NULL)
        {
            return "";
        }
        string ans= "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(cur==NULL)
                {
                    ans.append("null,");
                }
                else{
                    ans.append(to_string(cur->val)+',');
                }
                
                if(cur)
                {
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }
        return ans;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
        {
            return NULL;
        }
        queue<TreeNode*> q;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            
            getline(s,str,',');
            if(str=="null")
            {
                cur->left = NULL;
            }
            else{
                TreeNode* l = new TreeNode(stoi(str));
                cur->left = l;
                q.push(l);
            }
            
            getline(s,str,',');
            if(str=="null")
            {
                cur->right = NULL;
            }
            else{
                TreeNode* r = new TreeNode(stoi(str));
                cur->right = r;
                q.push(r);
            }
        }
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));