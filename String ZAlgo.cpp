class Solution
{
    public:
        int helper(string c,int z[]){
            int k=c.size();
            int l=0,r=0,pos;
            for(int i=1;i<k;i++){
                if(i>r){
                    l=i;
                    r=i;
                    while(r<k && c[r-l]==c[r]){
                        r++;
                    }
                    z[i]=(r--)-l;
                }else{
                    int pos=i-l;
                    if(z[pos]+i<=r){
                        z[i]=z[pos];
                    }else{
                        l=i;
                        while(r<k && c[r-l]==c[r]){
                            r++;
                        }
                        z[i]=(r--)-l;
                        
                    }
                }
            }
        }
        vector <int> search(string pat, string txt)
        {
            //code hee.
            string c=pat + "$" + txt;
            int k=c.size();
            int z[k];
            z[0]=0;
            helper(c,z);
            vector<int>ans;
            for(int i=0;i<k;i++){
                if(z[i]==pat.size()){
                    ans.push_back(i-pat.size());
                }
            }
            return ans;
        }
     
};
