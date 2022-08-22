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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int , map<int,multiset<int>>> m;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            TreeNode* temp = cur.first;
            int vertical = cur.second.first;
            int level = cur.second.second;
            m[vertical][level].insert(temp->val);
            
            if(temp->left)
            {
                q.push({temp->left,{vertical-1,level+1}});
            }
            if(temp->right)
            {
                q.push({temp->right,{vertical+1,level+1}});
            }
        }
        
        vector<vector<int>>ans;
        for(auto i: m)
        {
            vector<int> res;
            for(auto j: i.second)
            {
                res.insert(res.end(),j.second.begin(),j.second.end());
            }
            
            ans.push_back(res);
        }
        return ans;
    }
};