class Solution {
public:
    int singleNumber(vector<int>& nums) {

            if(nums.size()<2){
                nums[0];
            }

            for(int i=0;i<nums.size()-1;i++){

                    nums[i+1] = nums[i] ^ nums[i+1];
            }
        return nums[nums.size()-1];
    }
};