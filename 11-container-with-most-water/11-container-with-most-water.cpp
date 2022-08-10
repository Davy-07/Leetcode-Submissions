class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0;
        int right = height.size()-1;
        int max_water = 0;
        
        while(left<right)
        {
            int len = min(height[left],height[right]);
            max_water = max(max_water,(right-left)*len);
            if(height[left]<=len)
            {
                left++;
            }
            if(height[right]<=len)
            {
                right--;
            }
        }
        
        return max_water;
        
    }
};