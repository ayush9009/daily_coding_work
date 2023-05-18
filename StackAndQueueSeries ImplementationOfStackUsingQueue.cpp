//implemtation of Stack using two queues Time complexity:O(n) Space Complexity: O(2n)
//implemtation of Stack using single queues Time complexity:O(1) Space Complexity: O(n)
// class MyStack {
// public:
//     MyStack() {
        
//     }
//     queue<int>input,output;
//     void push(int x) {
//         while(!input.empty()){
//             output.push(input.front());
//             input.pop();
//         }
//         input.push(x);
//         while(!output.empty()){
//             input.push(output.front());
//             output.pop();
//         }
//     }
    
//     int pop() {
//        int x=input.front();
//        input.pop();
//        return x;
//     }
    
//     int top() {
//         return input.front();
//     }
    
//     bool empty() {
//         return input.empty();
//     }
// };

//implementation using single queue
class MyStack {
public:
    MyStack() {
        
    }
    queue<int>q;
    void push(int x) {
        int n=q.size();
        q.push(x);
        for(int i=0;i<n;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
       int x=q.front();
       q.pop();
       return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
