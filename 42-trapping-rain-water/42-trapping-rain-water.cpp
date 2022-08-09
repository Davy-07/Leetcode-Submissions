class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> max_left(height.size(),-1);
        vector<int> max_right(height.size(),-1);
        vector<int> min_l_r(height.size(),-1);
        int max_l = -1;
        int max_r = -1;
        for(int i=0;i<height.size();i++)
        {
            if(height[i]>max_l)
            {
                max_l = height[i];
            }
            max_left[i] = max_l;
        }
        
        for(int i=height.size()-1;i>=0;i--)
        {
            if(height[i]>max_r)
            {
                max_r = height[i];
            }
            max_right[i] = max_r;
        }
        
        for(int i=0;i<height.size();i++)
        {
            min_l_r[i] = min(max_left[i],max_right[i]);
        }
        
        int ans = 0;
        for(int i=0;i<height.size();i++)
        {
            ans+= min_l_r[i] - height[i];
        }
        return ans;
    }
};