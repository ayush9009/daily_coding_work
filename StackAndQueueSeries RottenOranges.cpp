class Solution {
public:
//    void helper(int i,int j,int n,int m,vector<vector<int>>& grid,int &ct){
//        if(i<0 || j<0 || i>=n || j>=m)return ;
//     //    if(grid[i][j]==2 || grid[i][j]==0)continue;
//     //    else if(grid[i][j]==1)grid[i][j]=2;
//     //    if(grid[i][j]==2 )continue;
//        if(grid[i][j]==1)
//        {
//            grid[i][j]=2;
//            ct++;
//         //    return true;
//         //    cout<<grid[i][j]<<" ";
//        }
//        helper(i,j-1,n,m,grid,ct);
//        helper(i-1,j,n,m,grid,ct);
//        helper(i,j+1,n,m,grid,ct);
//        helper(i+1,j,n,m,grid,ct);
//    }
    int orangesRotting(vector<vector<int>>& grid) {
        int res=-1;
        int n=grid.size();
        queue<vector<int>>q;
        vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        int ct=0;
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0)ct++; //taki non zero ki cnt rak sake aur agr akri mai ct=0 meanssab 2 hogye
                if(grid[i][j]==2)q.push({i,j});  //sirf rotten oranges push kar diye
            }
        }

        while(q.empty()==false){
            res++;  //means 1 minute is completed
            int size=q.size();
            for(int k=0;k<size;k++){
                vector<int>cur=q.front();
                ct--; //kuki we traverse one non zero digit,to uski cnt to kam karni padegi na
                q.pop();
                for(int i=0;i<4;i++){
                    int x=cur[0]+dir[i][0],y=cur[1]+dir[i][1];
                    if(x>=n || x<0 || y>=m || y<0 || grid[x][y]!=1)continue;
                    grid[x][y]=2;
                    q.push({x,y});
                }
            }
        }
        if(ct==0)return max(0,res);
       return -1;
    }
};
