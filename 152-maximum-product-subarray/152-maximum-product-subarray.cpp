class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = *max_element(nums.begin(),nums.end());
        int curMax = 1;
        int curMin = 1;
        int temp_max;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                curMax = 1;
                curMin = 1;
                continue;
            }
            temp_max = curMax*nums[i];
            curMax = max(max(curMax*nums[i],curMin*nums[i]),nums[i]);
            curMin = min(min(temp_max,curMin*nums[i]),nums[i]);
            ans = max(max(curMin,curMax),ans);
        }
        
        return ans;
    }
};