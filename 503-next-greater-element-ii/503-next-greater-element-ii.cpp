class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> ans(nums.size(),-1);
        stack<int> st;
        int n = nums.size();
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i%n])
            {
                st.pop();
            }
            if(i<n)
            {
                if(!st.empty())
                {
                    ans[i] = st.top();
                }
                else{
                    ans[i]=-1;
                }
            }
            st.push(nums[i%n]);
        }
        
        return ans;
    }
};