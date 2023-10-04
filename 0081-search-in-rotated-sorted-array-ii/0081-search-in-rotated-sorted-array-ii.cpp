class Solution {
public:
    bool search(vector<int>& nums, int target) {
            int low = 0;
            int high = nums.size()-1;
            int mid;
            bool ans = false;

            while(low<=high){

                    mid = (low+high)/2;
                    if(nums[mid]==target){
                        ans = true;
                        break;
                    }

                    if((nums[low]==nums[mid]) && (nums[high]==nums[mid])){
                        low++;
                        high--;
                    }
                    else{
                        if(nums[low]<=nums[mid]){
                            if(target>=nums[low] && target<nums[mid]){
                                high = mid-1;
                            }
                            else{
                                low = mid+1;
                            }
                        }
                        else{
                            if(target>nums[mid] && target<=nums[high]){
                                low= mid+1;
                            }
                            else{
                                high = mid-1;
                            }
                        }
                    }
            }
            return ans;
    }
};