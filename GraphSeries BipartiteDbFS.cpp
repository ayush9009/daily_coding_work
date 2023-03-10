bool dfsBipart(vector<vector<int>>& graph,int src,vector<int>&color){
       for(auto it:edges[src]){
         if(color[it]==-1){
           color[it]=1-color[src];
           if(!dfsBipart(edges,it,color))return false;
         }
       }
  return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
               color[it]=1;
                if(!dfsBipart(graph,i,color))
                    return false;
            }
        }
        return true;
    }
