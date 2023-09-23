class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = INT_MAX;
        int sell = 0;
        int profit = 0;
        for(int i=0;i<prices.size();i++)
        {
            buy = min(buy,prices[i]);
            sell = prices[i] - buy;
            profit = max(profit,sell);
        }

        return profit;
        
    }
};