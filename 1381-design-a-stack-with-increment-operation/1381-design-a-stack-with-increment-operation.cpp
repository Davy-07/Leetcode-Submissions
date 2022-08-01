class CustomStack {
    vector<int> st;
    int max;
public:
    CustomStack(int maxSize) {
        
        st.clear();
        max= maxSize;
        
    }
    
    void push(int x) {
        
        if(st.size()<max)
        {
            st.push_back(x);
        }
    }
    
    int pop() {
        
        int val=-1;
        if(st.size()>0)
        {
            val = st.back();
            st.pop_back();
        }
        return val;
    }
    
    void increment(int k, int val) {
        
        int n = st.size();
        for(int i=0;i<min(n,k);i++)
        {
            st[i]+=val;
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */