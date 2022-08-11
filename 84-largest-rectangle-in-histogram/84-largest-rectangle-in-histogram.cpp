class Solution {
public:
    
    vector<int> smaller_right(vector<int>& heights)
    {
        stack<pair<int,int>> right;
        int psuedo = heights.size();
        right.push({0,psuedo});
        vector<int> ans;
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(right.top().second!=psuedo && right.top().first>=heights[i])
            {
                right.pop();
            }
            ans.push_back(right.top().second);
            right.push({heights[i],i});
        }
        return ans;
    }
    
    vector<int> smaller_left(vector<int>& heights)
    {
        stack<pair<int,int>> left;
        int pseudo = -1;
        left.push({0,pseudo});
        vector<int> ans;
        
        for(int i=0;i<heights.size();i++)
        {
            while(left.top().second!=pseudo && left.top().first>=heights[i])
            {
                left.pop();
            }
            ans.push_back(left.top().second);
            left.push({heights[i],i});
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> left;
        vector<int> right;
        
        left = smaller_left(heights);
        right = smaller_right(heights);
        reverse(right.begin(),right.end());
        int length,breadth;
        int area = INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            length = heights[i];
            breadth = right[i]-left[i]-1;
            area = max(area,length*breadth);
        }
        
        return area;
    }
};