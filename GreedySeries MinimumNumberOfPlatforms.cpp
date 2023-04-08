  int findPlatform(int arr[], int dep[], int n)
    {
       sort(arr,arr+n);
       sort(dep,dep+n);
       int i=1,j=0;
       int cnt=1;
       int ans=1;
       while(i<n && j<n){
           if(arr[i]<=dep[j]){//means we neeed one extra platform
               cnt++;  
               i++;
           }else{
              cnt--; //means we dont need extra platform we reduced the cnt and increment the j
               j++;
           }
           ans=max(ans,cnt);
       }
       return ans;
    }
