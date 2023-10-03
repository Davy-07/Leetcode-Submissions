class Solution {
public:
    int search(vector<int>& nums, int target) {
        
            int left = 0;
            int right = nums.size()-1;
            int ans = -1;
            int mid;
            while(left<=right){
                mid = (left+right)/2;
                if(nums[mid]==target){
                    ans = mid;
                    break;
                }
                else{
                    if(nums[left]<=nums[mid]){
                        if(target>=nums[left] && target<nums[mid]){
                            right = mid-1;
                        }
                        else{
                            left = mid+1;
                        }
                    }
                    else{
                        if(target>nums[mid] && target<=nums[right]){
                            left = mid+1;
                        }
                        else{
                            right = mid-1;
                        }
                    }
                }
            }

            return ans;
    }
};