int countSmallerThanMid(vector<int>&arr,int target){   // in this funciton with the help of binary search we check how 
// many elements are less than target,if arr= 123456789 aur target=5 aur mid=4 to all elmetn in right side of 4 are less than 4
//4<=5 to low=mid+1 i.e low=5 5<=5 to low =mid+1 i.e 6 to ye gadbad hogi to high=mid-1; return low 0 based indexing se smjo to anser 5 ajaga lakin 1 based indexing to anser 6
    int low=0,high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)>>1;
        if(arr[mid] <= target)low=mid+1;
        
        else high=mid-1;
    }
    return low;
}
int Solution::findMedian(vector<vector<int> > &A) {
    
    //jab binary sarch ki bat aye to sarch space deka ja maximum kitna possible to yaha possible high=10^9 psoible
    int low=1; 
    int high=1e9;   //means 10^9
    int n=A.size();
    int m=A[0].size();
    while(low<=high){
        int mid=(low+high)>>1;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=countSmallerThanMid(A[i],mid);
            // with the help of countSmallerThanMid function we check in each row how many elements are less than mid
            // taki hum search space ko uske anusar shrink kar sake aur hume median nikalne mai asani ho 
        }
        if(cnt<=(n*m)/2)low=mid+1;  // n*m/2,kuki ,iss sey pata lag jaaga right jaye ya left, kuki agr supose agr long long n,aur long long m now (n*m) to kitna bda number bn jaga isliye divide by2
        else high=mid-1;
    }
    return low;
}
