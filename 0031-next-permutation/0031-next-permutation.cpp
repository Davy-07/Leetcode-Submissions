class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int break_point = -1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                break_point = i;
                break;
            }
        }
        int min_no = INT_MAX;
        int index;
        if(break_point == -1){
            sort(nums.begin(),nums.end());
        }
        else{
            for(int i=break_point+1;i<nums.size();i++){
                if(nums[i]>nums[break_point]){
                    if(nums[i]<min_no){
                        min_no = nums[i];
                        index = i;
                    }  
                }
            }
                
            swap(nums[index],nums[break_point]);
            sort(nums.begin()+break_point+1,nums.end());
            


        }


    }
};