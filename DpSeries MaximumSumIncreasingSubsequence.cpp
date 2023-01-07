int maxSumIS(int nums[], int n)  
	{  
// 	  same to same longest increasing subsequence kai jaisa bas vaha length thi to 1+dp[j]
// 	  karae thai yaha max sum hai to nums[i]+dp[j]
        int dp[n];
        int mx=0;
        for(int i=0;i<n;i++)dp[i]=nums[i];
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<dp[j]+nums[i]){
                    dp[i]=dp[j]+nums[i];
                }
            }
        }
        for(int i=0;i<n;i++){
            mx=max(dp[i],mx);
        }
       
        return mx;
	}  
