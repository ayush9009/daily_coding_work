#include <bits/stdc++.h>
vector<int>prevSmaller(vector<int>arr,int n){
    vector<int>prev(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
        if(st.empty())prev[i]=-1;
        else prev[i]=st.top();
        st.push(i);
    }
    return prev;
} 
// prev smaller concept
    //    3 6 4  2
    //    stack mai prev smaller hoga har element if stack.top()>=arr[i]then we remove it
// prev[i]-1 0 0 -1
// ye hi cheez agr last se karogey to next smaller mani jagi
// next[i]    3  3  3  4 2 ka next smaller 4(i.e n),4 next smaller 2 ,6 next smaller 4  
vector<int>nextSmaller(vector<int>arr,int n){
    vector<int>next(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
        if(st.empty())next[i]=n;
        else next[i]=st.top();
        st.push(i);
    }
    return next;
}
vector<int> maxMinWindow(vector<int> arr, int n) {
    // Write your code here.
    vector<int>answer(n,INT_MIN);
    vector<int>prev=prevSmaller(arr,n);
    vector<int>next=nextSmaller(arr,n);
    for(int i=0;i<n;i++){
        int length=next[i]-prev[i]-1;
        answer[length-1]=max(answer[length-1],arr[i]);  //max kuki jis jis window ki length 3 uska 
        // maximum lena mtlb ,min(elements of window of size 3),min(another windowelements of window of size 3)
        // to ab ye jitni bhi windows hai in sabka maxmim stoe kar na window of size of length of 3,vohi
        // to kara answer[lnegth-1]=max(arr[length-1],arr[i]); //smaller vagera to next and prev samller se find kr lia
    }
    for(int i=n-2;i>=0;i--){
        answer[i]=max(answer[i],answer[i+1]); //for every window size of l its answre>=l1,l2,l3
    }
    return answer;
}
