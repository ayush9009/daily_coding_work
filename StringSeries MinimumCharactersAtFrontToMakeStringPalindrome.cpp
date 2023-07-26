class Solution {
public:

    int lps(string str){
        int n=str.size();
        int lps[n];
        lps[0]=0;
        int len=0,i=1;
        while(i<n){
            if(str[i]==str[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len==0){lps[i]=0;i++;}
                else len=lps[len-1];
            }
        }
        return lps[n-1];
    }
    int minChar(string str){
        
    //Efficient apporach:KMP LPS ARRAY
    // apporach O(N) O(N)
    // For string = AACECAAAA
    // Concatenated String = AACECAAAA$AAAACECAA
    // LPS array will be {0, 1, 0, 0, 0, 1, 2, 2, 2, 
    //               0, 1, 2, 2, 2, 3, 4, 5, 6, 7}
    // this 7 indicates the largest suffix of reverse string matches with prfix of original string i.e AACECAA
    // means it indicates the size of string which is already paldinrome,means now we get which is palindrmoe
    // so length of stirng -7=9-7=2 these many charcters are needed 
    
    // suppose abc
    // so abc$cba
    // proper prefix=a ab (prefix of original string )
    // suffix a ba cba (suffix of reverse string)
    // longest suffix which is prper prefix=c ,3-1=2
    
     int n=str.size();
     string ans=str;
     reverse(str.begin(),str.end());
     string concat= ans +'$' + str;
     
     return n-lps(concat);
    //  optimseise apporach O(N) O(1)
    // int start=0,end=n-1;
    // int res=0;
    // while(start<end){
    //     if(str[start]==str[end]){
    //         start++;
    //         end--;
    //     }else{
    //         res++;  //count the charcter if not match
    //         start=0; //move the pointer to begining of string ,kuki front mai dekne
    //         end=n-res-1;  //reset the end pointer to end of string with reducted number of not matcing character
    //     //   end=n-res-1 kuki ab res se pata lag taht much character not match to n-res(ab inme check karne ki 
    //     // jaroart hai chacter match hore ya ni,start=0(kuki front  mai dekna ,aur vaise bhi hume hume bar bar check
    //     // karna padega till start<end ki how mant chacter need to add))
            
    //     }
    // }
    // return res;
        }
};
