class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size();
        int m=version2.size();
        int i=0,j=0;
         int num1=0,num2=0;
        while(i<n || j<m){
           
            while(i<n && version1[i]!='.'){
                num1=(num1*10)+(version1[i]-'0');
                i++;
            }
            while(j<m && version2[j]!='.'){
                num2=(num2*10)+(version2[j]-'0');
                j++;
            }
            if(num1>num2)return 1;  //like num1=2.33 num2=3.1 num2>num1 return -1
            else if(num1<num2)return -1; 
            num1=0;  //kuki . se pahle ka number check kar liya ab uske bad ka checkro 
            num2=0; //jaise version1=2.34 version2=2.35 so vrison2>version1
            i++; //thatwhy num1=0,num2=0 so that we check result after decimal
            j++;
        }
         return 0;
    }
   
};
