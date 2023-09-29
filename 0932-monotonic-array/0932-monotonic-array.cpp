class Solution {
public:
    bool increasing(std::vector<int>& nums){
        int ans = true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                ans = false;
                break;
            }
        }
        return ans;
    }

    bool decreasing(std::vector<int>& nums){
        int ans =true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                ans = false;
                break;
            }
        }
        return ans;
    }

    bool isMonotonic(std::vector<int>& nums) {
        bool inc = increasing(nums);
        bool dec= decreasing(nums);

        return inc||dec;
    }
};