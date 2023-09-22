class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int max_sum = INT_MIN;
        int cur_sum =0;
        for(int i=0;i<nums.size();i++){

                max_sum = max(max_sum,nums[i]);
                cur_sum+= nums[i];
                if(cur_sum>max_sum){
                    max_sum = cur_sum;
                }            
                else if(cur_sum<0){
                    cur_sum=0;
                }

        }
        return max_sum;
        
    }
};