#include<bits/stdc++.h>
bool bfsDetect(int src,vector<int>&visited,vector<int> adj[],int n){
    visited[src]=true;
//     vector<int>parent(n,-1);
    queue<pair<int,int>>q;
    q.push({src,-1});
//     queue<int>q;
//     q.push(src);
    while(!q.empty()){
        int u=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto v:adj[u]){
            if(!visited[v]){
                visited[v]=true;
//                 q.push(v);
//                 parent[v]=u;
                q.push({v,u});
            }
            else if(par!=v)return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    string str1="Yes";
    string str2="No";
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i] && bfsDetect(i,visited,adj,n))
            return str1;
    }
    return str2;
}
