class Solution {
  public:
    int canRepresentBST(int arr[], int n) {
        
        // jaise 40 30 35 80 100
        // abhi stacak mai 40 30 chle now s.top () i.e 30<35 to root=30 and s.pop() ab agr 30 se chota
        // koi aya array mai to reutrn false hojaga is sey greater to asake is ey chota ni
    //   find the next greater ,if u find the next smaller then return false;
       stack<int>s;
       int root=INT_MIN;
       for(int i=0;i<n;i++){
           if(arr[i]<root)return false
           while(s.empty()==false && s.top()<arr[i]){
               root=s.top();  //stack ki madath se greater element milta jara
               s.pop();//aur root mai miinimuma assign hojara,agr arr[i]<root to fasle
            //   jasie root=2 but arr[i]=1 1<2 to reutrn false but 3!<2 return true
            // sare khail next greater aur smaller ka
           }
           s.push(arr[i]);
       }
      
       return true;
    }
};
