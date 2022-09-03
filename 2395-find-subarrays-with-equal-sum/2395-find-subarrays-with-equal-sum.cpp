class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        
        unordered_map<int,int> m;
        int i=0;
        int j=0;
        int sum = 0;
        int count = 0;
        while(j<nums.size())
        {
            if(j-i+1!=2)
            {
                j++;
            }
            if(j-i+1==2)
            {
                sum = sum + nums[i] + nums[j];
                if(m.empty())
                {
                    m[sum] ++;
                }
                else if(m.find(sum)==m.end())
                {
                    m[sum]++;
                }
                else if(m.find(sum)!=m.end())
                {
                    m[sum]++;
                    if(m[sum]==2)
                    {
                        return true;
                    }
                }
                i++;
                j++;
                sum=0;
            }
        }
        return false;
        
    }
};