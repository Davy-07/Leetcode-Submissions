class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int size = nums.size();
        if(nums.size()==1) return nums[0] ;
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[size-1]!=nums[size-2]) return nums[size-1];

        int low = 1;
        int high = size - 2;
        int mid;
        int ans;
        while(low<=high){
            mid = (low+high)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                ans = nums[mid];
                break;
            }
            if((mid%2==0 && nums[mid-1]==nums[mid]) || (mid%2!=0 && nums[mid+1]==nums[mid])){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;

    }
};