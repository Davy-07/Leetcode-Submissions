class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        bool ans = false;
        int third = INT_MIN;
        stack<int> s;   

        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<third){
                ans = true;
                break;
            }
            while(!s.empty() && s.top()<nums[i]){
                third = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }

        return ans;


    }
};