class Solution {
public:
    bool dfs(int src,vector<int>adj[],vector<int>&vis,vector<int>&recSt){
        vis[src]=1;
        recSt[src]=1;
        
        for(auto v:adj[src]){
            if(!vis[v] && dfs(v,adj,vis,recSt)){
                return true;
            }
            else if(recSt[v])return true;
        }
        recSt[src]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        //detect cyclle in a directed graph using dfs
        
        int V=numCourses;
        vector<int>adj[V];
        for(int i=0;i<p.size();i++){
            int u=p[i][0];
            int v=p[i][1];
            
            adj[v].push_back(u);
        }

        vector<int>vis(V,0);
        vector<int>recSt(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,recSt))
                    return false;   //agr cyle bn ja to possible nhi hai
            }
        }
        return true;
    }
    
};
