class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(auto it: points)
        {
            pq.push({(it[0]*it[0])+(it[1]*it[1]),{it[0],it[1]}});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        
        while(pq.size()>0)
        {
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};