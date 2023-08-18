class Solution {
public:
//intution:both start from samepoint(fixed point),
    vector<vector<vector<vector<int>>>>dp;
    int helper(vector<vector<int>>& grid,int row1,int col1,int row2 ,int col2,bool &flag){
        
        int n=grid.size();
        if(row1>=n || row2>=n || col1>=n || col2>=n)return INT_MIN;
        if(row1==n-1 && row2==n-1 && col1==n-1 && col2==n-1){
            flag=true; //means both reach the destination
            return grid[row1][col1];
        }
        if(dp[row1][col1][row2][col2]!=-1)return dp[row1][col1][row2][col2];

        if(grid[row1][col1]==-1 || grid[row2][col2]==-1)return INT_MIN;
        int cnt=0;
        if(grid[row1][col1]==1 && grid[row2][col2]==1 && row1==row2 && col1==col2){
            cnt+=1;
        }else{
            cnt+=grid[row1][col1]+grid[row2][col2];
        }
        int choice1=helper(grid,row1+1,col1,row2+1,col2,flag);//both go downwards
        int choice2=helper(grid,row1,col1+1,row2,col2+1,flag);//both go rightwards
        int choice3=helper(grid,row1+1,col1,row2,col2+1,flag);// downwards, rightwards
        int choice4=helper(grid,row1,col1+1,row2+1,col2,flag);// rightwards ,downwards

        if(flag==true){
            cnt+=max(max(choice1,choice2),max(choice3,choice4));
            dp[row1][col1][row2][col2]=cnt;
            return cnt;
        }
        return dp[row1][col1][row2][col2]=0;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        if(grid[0][0]==-1 || grid[grid.size()-1][grid.size()-1]==-1)return 0;
        int n=grid.size();
        bool flag=0;
        dp.resize(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        return helper(grid,0,0,0,0,flag);
    }
};
