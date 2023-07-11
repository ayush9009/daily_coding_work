class Solution {
public:
   //easy question just combination concept nothing else
   //see if n=0 return 1
   //if n=1 means 10^1=10 so uniqye digits are from 0<10 i.e 10
   //if two digit number
//    so for first digit possible numbers are (1-9)(0 ni aaksakta first place )
//    so for second digit numbers are(0 and others ,exceptthenumberwhich is onfirstdigit )
//    yani if n=2 to 9*9
//    and if n=3 means three digit number to 9*9*8 (why (ttal number 10) to bache ab 8, kuki ek number first digit pai,aur ek nnumber dusri digit kai liye to 10-2=8)to aise bar bar numbers gat thai jange 
    int countNumbersWithUniqueDigits(int n) {
       if(n==0)return 1;
       int ans=10;
       int temp=9,cal=9;
       for(int i=0;i<n-1;i++){
           cal*=temp;
           ans+=cal;
           temp--;
       }
       return ans;
    }
};
