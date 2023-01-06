#include<bits/stdc++.h>
int ed(int m,int n,string &s1,string &s2){
        int dp[m+1][n+1];
    for(int i=0;i<=m;i++)dp[i][0]=i;
    for(int j=0;j<=n;j++)dp[0][j]=j;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1];
            else 
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    return dp[m][n];
}
int editDistance(string str1, string str2)
{
    //write you code here
    int m=str1.size();
    int n=str2.size();
    
    return ed(m,n,str1,str2);
}
