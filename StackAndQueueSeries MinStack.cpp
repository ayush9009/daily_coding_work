class MinStack {
public:
    stack<int>st,s1;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(s1.empty())s1.push(val);
        else if(s1.top()>=val)s1.push(val);
    }
    
    void pop() {
        
        if(st.top()==s1.top())
            s1.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return s1.top();
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
