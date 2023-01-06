#include<bits/stdc++.h>
int helper(int w,vector<int> &wt, vector<int> &value, int n, int dp[1001][1001]){
    if(w==0 || n==0)return 0;
    if(dp[n][w]!=-1)return dp[n][w];
    if(wt[n-1]<=w){
        return dp[n][w]=max(value[n-1]+helper(w-wt[n-1],wt,value,n-1,dp),helper(w,wt,value,n-1,dp));
    }else if(wt[n-1]>w){
        return dp[n][w]=helper(w,wt,value,n-1,dp);
    }
}
int maxProfit(vector<int> &value, vector<int> &wt, int n, int w)
{
	// Write your code here
    int dp[1001][1001];
    memset(dp,-1,sizeof(dp));
    return helper(w,wt,value,n,dp);
}
