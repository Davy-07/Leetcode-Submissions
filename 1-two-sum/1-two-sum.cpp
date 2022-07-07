class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
       bool flag= false;
       vector<int> ans;
       for(int i=0;i<nums.size()-1;i++)
       {
           for(int j=i+1;j<nums.size();j++)
           {
               if(nums[i]+nums[j]==target)
               {
                   flag=true;
                   ans.push_back(i);
                   ans.push_back(j);
                   break;
               }
           }
           if(flag==true)
           {
               break;
           }
       }
     
        return ans;
        
        
    }
};