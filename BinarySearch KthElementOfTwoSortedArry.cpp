int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        // for(int i=n;i<m;i++){
        //     arr1[i]=arr2[i];
        // }
        // sort(arr1,arr1+(n+m));
        // int t=0;
        // for(int i=0;i<k;i++){
        //     if(i==k-1){
        //         t=arr1[i];
        //         break;
        //     }
        // }
        // return t;
        // vector<int>result;
        // for(int i=0;i<n;i++){
        //     result.push_back(arr1[i]);
        // }
        // for(int i=0;i<m;i++){
        //     result.push_back(arr2[i]);
        // }
        // sort(result.begin(),result.end());
        // return result[k-1];
        
        //optimised apporach:
        if(n<m){
            return kthElement(arr2,arr1,m,n,k);
        };
         
         
         int low=max(0,k-m);//agr k=7 and arr.size()=6 ie.m=6 min elmet taken from arr1 =max(0,k-m) i.e(0,1)
         int high=min(k,n);  //agr k=4 and arr1.size()=3 min(k,n)i.e(4,3)=3
         
         while(low<=high){
             int cut1=(low+high)>>1; //cut1=2 suppose
             
             int cut2=k-cut1;   //5-2=3
             
             int l1=cut1==0 ? INT_MIN:arr1[cut1-1];
             int l2=cut2==0 ? INT_MIN:arr2[cut2-1];
             
             int r1=cut1==n ? INT_MAX:arr1[cut1];
             int r2=cut2==m ? INT_MAX:arr2[cut2];
             
             if(l1<=r2 && l2<=r1){
                 return max(l1,l2);
             }else if(l1>=r2){
                 high=cut1-1;  //i.e high=mid-1
             }else{
                 low=cut1+1; //i.e low=mid+1
             }
         }
         return 1;
    }
