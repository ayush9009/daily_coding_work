#include<bits/stdc++.h>
bool dfsDetect(int src,vector<int>&visited,vector<int> adj[],int parent){
    visited[src]=true;
    for(auto it:adj[src]){
        if(!visited[it] &&dfsDetect(it,visited,adj,src))return true;
        else if(it!=parent)return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    string str1="Yes";
    string str2="No";
    vector<int>adj[n];
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i] && dfsDetect(i,visited,adj,-1))
            return str1;
    }
    return str2;
}
