class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        int num =0;
        for(int i=0;i<nums.size()-2;i++)
        {
            int low = i+1;
            int high = nums.size()-1;
            int sum = 0;
            while(low<high)
            {
                sum = nums[low]+nums[high]+nums[i];
                if(sum==target)
                {
                    return sum;
                }
                else if(sum<target)
                {
                    low++;
                }
                else{
                    high--;
                }
                int diff = abs(sum-target);
                if(diff<ans)
                {
                    ans=diff;
                    num =sum;
                }
            }
        }
        return num;
        
    }
};