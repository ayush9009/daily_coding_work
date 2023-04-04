#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Write your code here.
    priority_queue<int,vector<int>,greater<int>>pq; 
    for(int i=0;i<k;i++){
        for(int j=0;j<arr[i].size();j++){
            pq.push(arr[i][j]);
        }
    }
    vector<int>result;
    while(pq.empty()==false){
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}
