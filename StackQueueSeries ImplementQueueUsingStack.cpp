class MyQueue {
public:
    // stack<int>s1,s2;
    // MyQueue() {
        
    // }
    
    // void push(int x) {
    //     while(!empty()) {
    //         s2.push(pop());
    //     }
        
    //     s1.push(x);
        
    //     while(!s2.empty()) {
    //         s1.push(s2.top());
    //         s2.pop();
    //     }
    // }
    
	// // We don't get any invalid operations to perform for pop and peek.
	// // Hence I didn't put empty check for pop and peek.
    // int pop() {
    //     int x = peek();
    //     s1.pop();
    //     return x;
    // }
    
    // int peek() {
    //     int x = s1.top();
    //     return x;    
    // }
    
    // bool empty() {
    //     return s1.empty();
    // }












    stack<int>input,output;
    MyQueue() {
        
    }
    void push(int x) {
       while(!input.empty()){
           output.push(input.top());
           input.pop();
       }
       input.push(x);
       while(!output.empty()){
           input.push(output.top());
           output.pop();
       }
       
    }
    int pop() {
       int x=input.top();
       input.pop();
       return x;
       
    }
    int peek() {
        return input.top();
        
    }
    bool empty() {
      return input.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
