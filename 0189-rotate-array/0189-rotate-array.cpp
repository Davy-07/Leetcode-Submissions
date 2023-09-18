class Solution {
public:
    void rotate(vector<int>& nums, int k) {

            k = k%nums.size();
            vector<int> temp;
            for(int i=nums.size()-k;i<nums.size();i++)
            {
                temp.push_back(nums[i]);
            }
            
            for(int i=nums.size()-k-1;i>=0;i--){
                nums[i+k] = nums[i];
            }

            for(int i=0;i<k;i++){
                nums[i] = temp[i];
            }
    }
};