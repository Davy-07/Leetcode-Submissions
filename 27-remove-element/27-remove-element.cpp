class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val)
            {
                auto it = nums.begin()+i;
                nums.erase(it);
                i--;
            }
        }
        
        
        return nums.size();
    }
};