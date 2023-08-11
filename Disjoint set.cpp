//what is the use of disjoint set
// since graph is changing all the time,whenever we build graph everytime it changes,suppose (4,5) 4 ,1 are not connected
// but after sometime (4,1) now they connected ,so evertime graph changes,suppose any time someone ask if these are 
// connected or not ,so for that we have to apply bfs or dfs.
// bfs or dfs 
// one component:123  //we do its dfs or bfs and see there is no 4 so we can simply say 1 and 4 are not conncted 
// another compoent:456

// so bfs/dfs time complexity=O(V+E),v:vertices,E:edges
// so for doing this in constant time ,the approach came in existence is dijoint set
// wchih uses two things,parent and union(perform by rank or size,genreally rank is use)

// so disjoint is mainly use whenever we have to find connected  or not in constant time
class Solution
{
    public:
    //Function to merge two nodes a and b.
    int findParent(int i,int par[],int rank1[]){
        while(i!=par[i]){
            i=par[i];
        }
        return i;
    }
    void union_( int a, int b, int par[], int rank1[]) 
    {
        //code here
        int x=findParent(a,par,rank1);
        int y=findParent(b,par,rank1);
        if(x==y)return ;//means parent same ,so they are in same compoent 
        if(rank1[x]<=rank1[y]){
            rank1[y]++;
            par[x]=y;
        }
        else if(rank1[y]<=rank1[x]){
            rank1[x]++;
            par[y]=x;
        }else{
            par[y]=par[y];
            rank1[y]++; //kuki y ,x mai juda to x ki rank bad gyi
        }
        
        return;
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        //code here
        return findParent(x,par,rank1)==findParent(y,par,rank1);
    }
};
