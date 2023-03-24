class Solution{
    public:
    
    void findPathHelper(int i,int j,vector<vector<int>>&m,vector<string>&ans,string move,vector<vector<int>>&vis,int n){
        if(i==n-1 && j==n-1){
            ans.push_back(move);
            return;
        }
        
        //downward direction
        if(i+1<n && !vis[i+1][j] && m[i+1][j]==1){
            vis[i][j]=1;
            findPathHelper(i+1,j,m,ans,move+'D',vis,n);
            vis[i][j]=0;
        }
        //leftward direction
        if(j-1>=0 && !vis[i][j-1] && m[i][j-1]==1){
            vis[i][j]=1;
            findPathHelper(i,j-1,m,ans,move+'L',vis,n);
            vis[i][j]=0;
        }
        //rightward direction
        if(j+1<n && !vis[i][j+1] && m[i][j+1]==1){
            vis[i][j]=1;
            findPathHelper(i,j+1,m,ans,move+'R',vis,n);
            vis[i][j]=0;
        }
        //leftward direction
        if(i-1>=0 && !vis[i-1][j] && m[i-1][j]==1){
            vis[i][j]=1;
            findPathHelper(i-1,j,m,ans,move+'U',vis,n);
            vis[i][j]=0;
        }
    }
    vector<string>helper(vector<vector<int>>&m,int n){
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        
        if(m[0][0]==1)findPathHelper(0,0,m,ans,"",vis,n);
        return ans;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string>t;
        t.push_back("-1");
        vector<string>ans=helper(m,n);
        if(ans.size()==0){
            return t;
        }
        return ans;
    }
};
