//Egg Dropping Problem
//recursive code:
class Solution
{
    public:
    int solve(int e,int f){
        if(e==1 || f==0 || f==1)return f;
        int mn=INT_MAX;
        for(int k=1;k<=f;k++){
            int temp=1+max(solve(e-1,k-1),solve(e,f-k));
            mn=min(mn,temp);
        }
        return mn;
    }
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
      
        return solve(n,k);
    }
};
//Memoisation code,
class Solution
{
    public:
    int dp[201][201];
    int solve(int e,int f){
        if(e==1 || f==0 || f==1)return f;
        if(dp[e][f]!=-1)return dp[e][f];
        int mn=INT_MAX;
        for(int k=1;k<=f;k++){
            int temp=1+max(solve(e-1,k-1),solve(e,f-k));
            mn=min(mn,temp);
        }
        return dp[e][f]=mn;
    }
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};




