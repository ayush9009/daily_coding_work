class Solution {
public:
    //Complete Connected Components
    void dfs(vector<int>&vis,int src,vector<vector<int>>&adj,int &nodes,int &edges){
        nodes++;
        edges+=adj[src].size();
        vis[src]=true;
        for(auto v:adj[src]){
            if(!vis[v])dfs(vis,v,adj,nodes,edges);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int cnt=0,errors=0;
        // int n=edges.size();
       vector<vector<int>>adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                int nodes=0,edges=0;
                dfs(vis,i,adj,nodes,edges);
                if(edges!=(nodes*(nodes-1)))errors++;  //ye check karne kai liye har ek pair kai beech mai edge hai ya nahi,for example abi edges=0,nodes=0but for node 0 kai liye jab loop to nodes=3,
                // ab ye deko 0-1,0-2   1-0,1-2   2-1,2-0  ye connected component ha,yani complete connected
                // componnent kai liye edges=n*(n-1) hona jarori nahi to vo complete connected component ni h
            }
        }
        return cnt-errors;
    }
};
