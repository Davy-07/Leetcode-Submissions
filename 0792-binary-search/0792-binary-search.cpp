class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size()-1;
        int mid = (low+high)/2;
        int ans =-1;
        while(low<=high){

                if(nums[mid]==target){
                    ans =  mid;
                    break;
                }
                else if(nums[mid]>target){
                    high = mid-1;
                    mid = (high+low)/2;
                }
                else{
                    low = mid+1;
                    mid = (high+low)/2;
                }
        }

        return ans;
    }
};