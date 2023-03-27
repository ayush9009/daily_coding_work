class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isSafe(int node,int color[],bool graph[101][101],int x,int n){
        for(int k=0;k<n;k++){ //check for every possible adj of node
        // grpah[k][node]==1 means there is edge from k to node and vice versa also true
        //color[k]==x matlb adj ka bhi same color to dikkt
            if(k!=node && graph[k][node]==1 && color[k]==x)return false;
        }
        return true;
    }
    bool solve(int node,int color[],bool graph[101][101],int m,int n){
        if(node==n)return true;  //mtlb we reach to end ,we reach to end if only if no one return false,so we 
        // return true
        
        for(int i=1;i<=m;i++){  //try coloring from every number
            if(isSafe(node,color,graph,i,n)){
                color[node]=i;
                if(solve(node+1,color,graph,m,n))return true;
                color[node]=0;  //backtrack taki agr koi aur color try kar sake
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n]={0};
         
         if(solve(0,color,graph,m,n))return true;
         return false;
    }
};
