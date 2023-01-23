class Solution
{
	public:
	
	int findMinVer(int V, vector<bool> &visited,vector<int> &dist){
	    
	    int min = INT_MAX;
	    
	    int vertex;
	    
	    for(int i = 0; i < V; i++){
	        
	        if(visited[i] == false && dist[i] < min){
	            vertex = i;
	            min = dist[i];
	        }
	    }
	    
	    return vertex;
	}

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        vector<bool> visited(V,false);
        vector<int> dist(V,INT_MAX);
        
        dist[S] = 0;
        
        for(int i = 0;i <  (V-1);i++){
            
            int u = findMinVer(V,visited,dist);
            
            visited[u] = true;
            
            for(auto v : adj[u]){
                
                if(!visited[v[0]]   && (dist[u] + v[1]) < dist[v[0]])
                {
                    dist[v[0]] = dist[u] + v[1];
                }
            }
        }
        return dist;
    }
};
