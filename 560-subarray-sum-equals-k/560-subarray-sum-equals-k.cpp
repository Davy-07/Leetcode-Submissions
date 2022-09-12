class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        vector<int> prefix(nums.size(),0);
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i] = nums[i] + prefix[i-1];
        }
        
        int ans = 0;
        
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++)
        {
            if(prefix[i]==k)
            {
                ans++;
            }
            
            if(m.find(prefix[i]-k)!=m.end())
            {
                ans+=m[prefix[i]-k];
            }
            
            m[prefix[i]]++;
        }
        
        return ans;
        
    }
};