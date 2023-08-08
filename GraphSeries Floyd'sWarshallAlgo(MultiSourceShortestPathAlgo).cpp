class Solution {
  public:
  
  //FLOYDS WARSHALL ALGORITHM 
  //MULTI SOURCE SHORTEST PATH ALGORITHM
	void shortest_distance(vector<vector<int>>&mat){
	    // Code here
	    //here we aleady given adjancey matrxi ,suppose if i->j there is edge then there is some value in matrxi
	   // but if there is no edge from i->j then mat[i][j]=-1 which deontes that this edge not exist or not contains any weight
	    int n=mat.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(mat[i][j]==-1){ //means this edge does not contain any weight means,this edge not exist
	                mat[i][j]=1e9;
	            }
	            if(i==j)mat[i][j]=0;  //mat[0][0]=0 souce to source 0 hoga
	        }
	    }
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	               // k denotes via
	               // mat[4][1]=mat[4][0]+mat[0][1]
	                //it means here we go from one node to every other node via k,in that end we get shortsetpath matrix
	                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
	                
	            }
	        }
	    }
	     for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(mat[i][j]==1e9){ 
	                mat[i][j]=-1;
	            }
	        }
	    }
	}
};
