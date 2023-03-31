class Solution {
public:
//badiya question
    // int helper(string s1,string s2){
        //this question similar to lcs but here you have to add ascii values also
    //     int dp[s1.size()+1][s2.size()+1];
    //     int m=s1.size(),n=s2.size();
    //     for(int i=0;i<=m;i++){
    //         for(int j=0;j<=n;j++){
    //             if(i==0 || j==0)dp[i][j]=0;
    //             else if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
    //             else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    //         }
    //     }
    //     return dp[m][n];
    // }
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        int dp[m+1][n+1];

        dp[0][0]=0;

        for(int i=0;i<m;i++){//base cases bas ascii value aur add karte jare inme hum thats the change
        // nahi to same aise hi kare
            dp[i+1][0]=dp[i][0]+s1[i];
        }  
        for(int j=0;j<n;j++){
            dp[0][j+1]=dp[0][j]+s2[j];
        }    
        // here dp[i][j+1] dp[i]mmeans we not include s1 character
        // here dp[i+1][j]  dp[j] means we include s2 character 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s1[i]==s2[j]){ 
                    //agr character equal to jo value chlti ari vo hi liye chlo
                    dp[i+1][j+1]=dp[i][j];
                }else{
                    //delete character either from s1 or s2
                    // dp[i][j+1]+s[i] mtlb we dont incude charcter from s1[i] and so we include+s[i]
                    // its ascii value
                    dp[i+1][j+1]=min(dp[i][j+1]+s1[i],dp[i+1][j]+s2[j]);
                }
            }
        }
        return dp[m][n];
    }
};
