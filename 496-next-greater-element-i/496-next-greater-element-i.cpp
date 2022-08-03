class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            auto it = find(nums2.begin(),nums2.end(),nums1[i]);
            if(it==nums2.end()-1)
            {
                ans.push_back(-1);
            }
            else{
                bool flag=false;
                for(auto it2=it+1;it2<nums2.end();it2++)
                {
                    if(*it2>nums1[i])
                    {
                        flag = true;
                        ans.push_back(*it2);
                        break;
                    }
                    
                }
                if(!flag)
                {
                    ans.push_back(-1);
                }
            }
        }
        return ans;
        
    }
};