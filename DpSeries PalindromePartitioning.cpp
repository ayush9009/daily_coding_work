class Solution{
public:
    int dp[501][501];
    bool isPalindrome(string &str,int i,int j){
        if(i==j)return true;
        if(str[i]!=str[j])return false;
        
        if(i<j+1){
            return isPalindrome(str,i+1,j-1);
        }
        return true;
    }
    int solve(string &str,int i,int j){
        if(i>=j)return 0;
        if(isPalindrome(str,i,j))return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp=1+solve(str,i,k)+solve(str,k+1,j);
            ans=min(temp,ans);
        }
        return dp[i][j]=ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        int n=str.size();
        return solve(str,0,n-1);
    }
};
