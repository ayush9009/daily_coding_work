#include<bits/stdc++.h>
using namespace std;
double multiply(double num,int n){
  double ans=1.0;
  for(int i=1;i<=n;i++)ans=ans*num;
  return ans;
}
int NthRoot(int n, int m) {
  // Write your code here.
  double low=1;
  double high=m;
  double eps=1e-6;
  while((high-low)>eps){
    double mid=(low+high)>>1;
    if(multiply(mid,n)<m)low=mid;
    else high=mid;
  }
  cout<<low<<endl;
}
