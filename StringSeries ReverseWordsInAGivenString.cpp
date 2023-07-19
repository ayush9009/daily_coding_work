class Solution {
public:
// VVIP QUESTION PEN AND PAPER NEEDED TO AVOID FAILURE IN HIDDEN TEST CASES
    string reverseWords(string s) {
            reverse(s.begin(),s.end());
    //    eulb si yks eht
       int i=0,n=s.size();
       int start=0,end=0;
       while(i<n){
           while(s[i]!=' ' && i<n){
               s[end++]=s[i++];
           }
           if(start<end){
               reverse(s.begin()+start,s.begin()+end);
               if(end==n)break;
               
               s[end++]=' ';
               start=end;  
               
           }
           i++;
       }
       if(end>0 && s[end-1]==' ')s.resize(end-1);
        // cout<<n<<" "<<end<<endl;
        return s;











    //     reverse(s.begin(), s.end());
    //     int n = s.size();
    //     int strt = 0, end = 0;
    //     int itrtr = 0;
    //     while (itrtr < n) {
    //         while (itrtr < n && s[itrtr] != ' ')
    //             s[end++] = s[itrtr++];

    //         if (strt < end) {
    //             reverse(s.begin() + strt, s.begin() + end); 
    //             if (end == n) break;
    //             s[end++] = ' ';
    //             strt = end;
    //         }
    //         itrtr++; 
    //     }
    //     if (end > 0 && s[end-1] == ' ')   s.resize(end-1);
    //    else  s.resize(end);
    // return s

   
   
    }
};
