class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void findTopoSort(int src,vector<int>adj[],vector<int>&visited,stack<int>&stk){
	    visited[src]=true;
	    for(auto it:adj[src]){
	        if(!visited[it]){
	            findTopoSort(it,adj,visited,stk);
	        }
	    }
	    stk.push(src);
	}
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	      // code here
	   // topoogival sort of direct edge(u,v) is that every vertex u comes before v,
	   //topologival sort different from dfs in this ,first we push all the adjacents of a node to stack then we 
	   //when all its adjacent are pushed to stack then we push this node to stack
	   vector<int>visited(v,0);
	   stack<int>stk;
	   for(int i=0;i<v;i++){
	       if(!visited[i]){
	           findTopoSort(i,adj,visited,stk);
	       }
	   }
	   vector<int>topo;
	   while(!stk.empty()){
	       topo.push_back(stk.top());
	       stk.pop();
	   }
	   return topo;
	}
};
