#include<bits/stdc++.h>
int cutRod(vector<int>& price,int N) {
  
//     ind goes from 0 to n-1 and N goes from 1 to N
//         therfore we return dp[n-1][n]
    vector<vector<int>> dp(N,vector<int>(N+1,-1));
  //  pahle n denotes prices n+1 deontes len
    
    for(int i=0; i<=N; i++){
//         agr first vala zero yani len=1
        dp[0][i] = i*price[0];
      //  becasue last guy is length of 1 and suppose n=5
  //          to 1*1*1*1*1 itni cost lagegi i.e i*price[0] kuki akri amai //price[0] hi to hoga
         //   0 1  2 3 4 hai to akri mai 0 vala dibba denoteslen1 i.eind+1
    }
    
    for(int ind=1; ind<N; ind++){
//         ab ek case to dekliya agr ,yani base case
        for(int length =0; length<=N; length++){
        
             int notTaken = 0 + dp[ind-1][length];
    
             int taken = INT_MIN;
//             if(n=5) then len of rod are as 0 1 2 3 4
//             to agr hum index 4 pai to len ind+1 i.e 5 hai 
             int rodLength = ind+1;
             if(rodLength <= length) 
                 //agr rodlength<=length to consider karenge
                taken = price[ind] + dp[ind][length-rodLength];
        
             dp[ind][length] = max(notTaken,taken);   
        }
    }
    
    return dp[N-1][N];
}
