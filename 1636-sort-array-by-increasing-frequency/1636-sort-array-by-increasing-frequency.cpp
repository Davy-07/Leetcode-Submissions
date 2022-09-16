class Solution {
public:
    
    class comparator{
      
            public:
            bool operator()(pair<int,int> const &a, pair<int,int> const &b)
            {
                return (a.second==b.second) ? a.first<b.first : a.second>b.second;
            }
    };
    
    vector<int> frequencySort(vector<int>& nums) {
        
        map<int,int> m;
        if(nums.size()==1)
        {
            return nums;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> pq;
        for(auto it:m)
        {
            pq.push({it.first,it.second});
        }
        
        vector<int> ans;
        
        while(pq.size()>0)
        {
            int x = pq.top().second;
            for(int i=0;i<x;i++)
            {
                ans.push_back(pq.top().first);
            }
            pq.pop();
        }
        
        return ans;
    }
};