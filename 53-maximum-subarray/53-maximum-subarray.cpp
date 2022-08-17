class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        int cur_sum = 0;
        int max_sum = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            max_sum = max(max_sum , nums[i]);
            cur_sum += nums[i];
            if(cur_sum > max_sum)
            {
                max_sum = cur_sum;
            }
            else if(cur_sum < 0)
            {
                cur_sum = 0;
            }
        }
        return max_sum;
        
    }
};