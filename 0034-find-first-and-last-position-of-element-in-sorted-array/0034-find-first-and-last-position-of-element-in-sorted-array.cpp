class Solution {
public:
    int binary_search(vector<int>& nums , int target){
        int ans = -1;
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while(low<=high){
            mid = (low+high)/2;
            if(nums[mid]==target){
                ans = mid;
                break;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> ans;
            int pos = binary_search(nums,target);
            if(pos==-1){
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }

            int first = pos;
            int last = pos;
            int x = first;
            int y = last;

            while(first>=0 && nums[first]==target){
                x = first;
                first--;
            }

            while(last<nums.size() && nums[last]==target){
                y = last;
                last++;
            }

            ans.push_back(x);
            ans.push_back(y);
            return ans;
    }
};