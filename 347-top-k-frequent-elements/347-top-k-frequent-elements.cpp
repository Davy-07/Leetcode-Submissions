class Solution {
public:
    
    class comparator{
        public:
        bool operator()(pair<int,int> const &a,pair<int,int> const &b)
        {
            return a.second < b.second;
        }
            
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> pq;
        for(auto it:m)
        {
            pq.push({it.first,it.second});
        }
        
        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};