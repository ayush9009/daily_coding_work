#include<bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    //detect ccyle in directed graph using dfs
   vector<int>adj[n];
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    int count=1;
    for(int i=0;i<n;i++){
        if(indegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:adj[u]){
            if(--indegree[v]==0){
                q.push(v);
                count++;
            }
        }
    }
    if(count!=n)return true;
    return false;
}
