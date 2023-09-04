class Solution
{
    public:
    void helper(string str,int lps[]){
        int n=str.size(),len=0;
        lps[0]=0;
        int i=1;
        while(i<n){
            if(str[i]==str[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len==0){
                    lps[i]=0;i++;
                }else{
                    len=lps[len-1];
                }
            }
        }
    }
        vector <int> search(string pat, string txt)
        {
            //code hee.
            int i=0,j=0,f=0;
            vector<int>result;
            int m=pat.size(),n=txt.size();
            int lps[m];
            helper(pat,lps);
            while(i<n){
                if(pat[j]==txt[i]){
                    i++;j++;
                }
                if(j==m){
                    f++;
                    result.push_back(i-j+1);
                    j=lps[j-1];
                    // result.push_back(i-j+1);
                }
                else if(i<n && pat[j]!=txt[i]){
                    if(j==0){i++;}
                    else{
                        j=lps[j-1];
                    }
                }
            }
            if(f==0)result.push_back(-1);
            return result;
        }
     
};
