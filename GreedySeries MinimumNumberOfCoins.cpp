#include<bits/stdc++.h>
using namespace std;
void findMin(int V){
  int deno[]={1,2,5,10,50,100,500,1000};
  int n=9;
  vector<int>ans;
  for(int i=n-1;i>=0;i--){
    while(V>=deno[i]){
      V-=deno[i];
      ans.push_back(deno[i]);
    }
  }
  for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
  }
}
