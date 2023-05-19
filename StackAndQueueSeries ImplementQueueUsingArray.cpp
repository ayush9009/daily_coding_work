#include <bits/stdc++.h> 
// class Queue {
// public:
//     int frnt=-1,rear=-1;
//     // int arr[100];
//     vector<int>arr;
//     Queue() {
//         // Implement the Constructor
//     }

//     /*----------------- Public Functions of Queue -----------------*/

//     bool isEmpty() {
//         // Implement the isEmpty() function
//        return (frnt==-1 && rear==-1);
//     }

//     void enqueue(int data) {
//     //    if(rear==100-1){ //means case of overflow
//     //        return;
//     //    }
//        if(frnt==-1 && rear==-1){   //means queue is empty
//            frnt=0;
//            rear=0;
//        }else{
//            rear++;   //means queue is not empty
//        }
//     //    arr[rear]=data;
//     arr.push_back(data);

//     }

//     int dequeue() {
//         int x=-1;
//         if(frnt==-1 || frnt>rear)return -1;  //means case of underflow
//         else{
//              x=arr[frnt];
//             if(frnt==rear){
//                 frnt=-1;
//                 rear=-1;
//             }else{
//                 frnt++;
//             }
//         }
//         return x;
//     }

//     int front() {
//         if(frnt==-1)return -1;
//         return arr[frnt];
//     }
// };
class Queue {
public:
    int qfront, rear, size, queueSize;
    int q[100010];
    Queue() {

        // Intialise the queue with 0 elements.
        rear = 0;
        qfront = 0;
        size = 0;
        queueSize = 100010;

    }

    // Function to check if the queue is empty.
    bool isEmpty() {
        if (qfront == rear) {
            return true;
        }
        return false;
    }

    void enqueue(int data) {

        // Push the current element in the queue.
        q[rear] = data;
        rear = rear + 1;

        // Increase the value of size.
        size++;
    }

    int dequeue() {

        // Check if the queue is empty.
        if (isEmpty()) {
            return -1;
        }

        int ans = q[qfront];
        qfront++;
        size--;
        if (qfront == rear) {
            qfront = 0;
            rear = 0;
        }
        return ans;
    }

    int front() {

        // Check if the queue is empty.
        if (isEmpty()) {
            return -1;
        }

        // Return the element at front.
        return q[qfront];
    }
};
