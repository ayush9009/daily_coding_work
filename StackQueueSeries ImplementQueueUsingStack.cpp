
    stack<int>s1,s2;
    MyQueue() {
        
    }
    void push(int x) {
        s1.push(x);
       
    }
    int pop() {
        int  ans=peek();
        s2.pop();
        return ans;
    }
    int peek() {
        if(s2.empty()){
            while(s1.empty()==false){
            s2.push(s1.top());
            s1.pop();
            }
        }
        return s2.top();
    }
    bool empty() {
        return s2.empty();
    }
};
