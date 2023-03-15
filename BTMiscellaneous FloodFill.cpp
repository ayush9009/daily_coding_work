class Solution {
public:
    void dfs(int nrow,int ncol,vector<vector<int>>&ans,vector<vector<int>>&image,int newColor,int delRow[],int delCol[],int iniColor){
        ans[nrow][ncol]=newColor;  //yani ye visited hogya tabhi iske liye dfs call hua,aur new color se updatekrdiya
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int row=nrow+delRow[i];
            int col=ncol+delCol[i];
            //4 hi to dirctions hai
            if(row>=0 && row<n && row<n && col<m && image[row][col]==iniColor && ans[row][col]!=newColor){
                dfs(row,col,ans,image,newColor,delRow,delCol,iniColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>>ans=image;
        int iniColor=image[sr][sc];
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        dfs(sr,sc,ans,image,newColor,delRow,delCol,iniColor);
        return ans;
    }
};
