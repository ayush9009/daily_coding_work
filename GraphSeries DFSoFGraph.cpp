class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int>result;
    void dfs(int src,vector<int>&visited, vector<int> adj[]){
        visited[src]=true;
        result.push_back(src);
            for(auto it:adj[src]){
                if(!visited[it]){
                dfs(it,visited,adj);
                }
            }
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        dfs(0,visited,adj);
        return result;
    }
};
