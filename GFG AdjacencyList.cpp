class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>>result(V);
        for(int i=0;i<edges.size();i++){
            // pair<int,int>res=it[0];
            int node1=edges[i].first;
            int node2=edges[i].second;
            // int node2=res.second;
            result[node1].push_back(node2);
            result[node2].push_back(node1);
            
            
        }
        return result;
          
    }
  
};
