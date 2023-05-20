#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    vector<int>st;
    int index;
    int n;
    Stack(int n) {
        // Write your code here.
        this->st.resize(n);
        this->index=-1;
        this->n=n;
    }

    void push(int num) {
        // Write your code here.
        if(index!=n-1){
            ++index;
            st[index]=num;
        }
    }

    int pop() {
        // Write your code here.
        if(index!=-1){
            --index;
            return st[index+1];
        }else{
            return -1;
        }
    }
    
    int top() {
        // Write your code here.
        if(index!=-1){
            return st[index];
        }else{
            return -1;
        }
    }
    
    int isEmpty() {
        // Write your code here.
        if(index!=-1){
            return 0;
        }else{
            return 1;
        }
    }
    
    int isFull() {
        if(index!=n-1){
            return 0;
        }else{
            return 1;
        }
    }
    
};
