class Solution
{
    public:
        vector <int> search(string p, string s)
        {
            //code hee.
            int cnt=0,l=0,r=0,pos;
            string c=p + '$' + s;
            int m=p.size();
            int k=s.size();
            int zarr[k];
            zarr[0]=0;
            for(int i=1;i<k;i++){
                if(i>r){
                    //resetting l and r
                    l=i;
                    r=i;
                     //calculating zarr[i]
                    while(r<k && c[r-l]==c[r]){
                        r++;
                    }
                    zarr[i]=r-l;
                    r--;
    
                if(zarr[i]==m)cnt++;
                else{
                    int pos=i-l;
                    if(zarr[pos]+i<=r){
                        zarr[i]=zarr[pos];
                        //check if zarr[i] is equal to length of p or not
                        if(zarr[i]==m)cnt++;
                    }else{
                        l=i;
                        //calculating z[i]
                        while(r<k && c[r-l]==c[r]){
                            r++;
                        }
                        zarr[i]=r-l;
                        r--;
                        if(zarr[i]==m){
                            cnt++;
                        }
                    }
                }
            }
            return cnt;
        }
     
};
