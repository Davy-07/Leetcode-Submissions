class StockSpanner {
    
    int i=0;
    stack<pair<int,int>> s;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans;
        while(!s.empty() && s.top().first<=price)
        {
            s.pop();
        }
        if(!s.empty())
        {
            ans = i -s.top().second;
        }
        else{
            ans = i+1;
        }
        
        s.push({price,i});
        i++;
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */