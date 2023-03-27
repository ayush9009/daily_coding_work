class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        // brute force :hashmap
        // better approach :using xor
        //optimised approach :binary search
        // int res=0;
        // for(int i=0;i<n;i++){
        //     res^=arr[i];
        // }
        // return res;
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            
            if(mid%2==0){
                if(arr[mid]==arr[mid+1])l=mid+2;
                else r=mid;
            }else if(mid%2==1){
                if(arr[mid]==arr[mid-1])l=mid+1;
                else r=mid-1;
            }
        }
        return arr[l];
    }
};
