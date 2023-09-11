class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
       vector<int> ans;
       unordered_map<int,int> m;
       int diff;
        for(int i=0;i<nums.size();i++)
        {
                diff = target - nums[i];
                if(m.find(diff)!=m.end())
                {
                    ans.push_back(i);
                    ans.push_back(m[diff]);
                    break;
                }
            m[nums[i]] = i;
        }
        return ans;
        
    }
};