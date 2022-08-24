class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int sum = 0;
        int max_sum = INT_MIN;
        
        for(int i=1;i<nums.size();i++)
        {
            
            sum+=nums[i-1];
            max_sum = max(max_sum,sum);
            
            if(nums[i-1]>=nums[i])
            {
                sum = 0;
            }
        }
        sum+=nums[nums.size()-1];
        max_sum = max(max_sum,sum);
        return max_sum;
        
        
    }
};