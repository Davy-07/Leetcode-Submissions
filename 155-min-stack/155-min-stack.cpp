class MinStack {
    stack<pair<int,int>> s;
    int min_val;
public:
    MinStack() {
        min_val = INT_MAX;
    }
    
    void push(int val) {
       if(s.empty())
       {
           s.push({val,val});
       }
        else{
            s.push({val,min(val,s.top().second)});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        
        return(min(s.top().first,s.top().second));
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */