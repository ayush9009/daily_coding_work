class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	   // according to bellman algo
	   //in worst case after n-1 iteration we get shortest path dist array,if after n-1 iteration still the value
	   //of dist[i] reduces it means there exist negative cycle ,because negative cycle exists in every rotation the
	   //value of dist[i] is reduces,that's how we check negative cylce in graph
	    vector<int>dist(n,-1);
	    dist[0]=0;
	    int flag=0;
	    for(int i=0;i<n-1;i++){ //n-1 iteration perform 
	        for(auto it:edges){
	            int u=it[0];
	            int v=it[1];
	            int wt=it[2];
	            if(dist[u]+wt<dist[v])dist[v]=dist[u]+wt;
	        }
	    }
	    for(auto it:edges){
	            int u=it[0];
	            int v=it[1];
	            int wt=it[2];
	            if(dist[u]+wt<dist[v]){
	                flag=1;
	                break;
	            }
	    }
	    return flag;
	}
};
