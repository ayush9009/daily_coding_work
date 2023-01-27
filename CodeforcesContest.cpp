#include<bits/stdc++.h>
using namespace std;
int main(){
int n; 
 cin >> n; 
 int arr[n][n-1]; 
 for (int i = 0; i < n; i++) 
 { 
  for (int i1 = 0; i1 < n-1; i1++) 
  { 
   cin >> arr[i][i1]; 
  } 

 } 
 /// 
 vector<int> ans; 
 vector<pair<int,int>> vc; 
 for (int i = 0; i < n-1; i++) 
 { 
  set<int> st; 
  vector<int> vv; 
  for (int i1 = 0; i1 < n; i1++) 
  { 
   int k=st.size(); 
   st.insert(arr[i1][i]); 
   if(k!=st.size()) vv.push_back(arr[i1][i]); 
  } 
  vc.push_back(make_pair(vv[0],vv[1])); 
 } 
 int x=vc[0].first; 
 int y=vc[0].second; 
 int x1=vc[1].first; 
 int y1=vc[1].second;
 int r; 
 if(x==x1 or x==y1) r=y; 
 else r=x; 
 cout << r << ' '; 
 for (int i = 0; i < vc.size(); i++) 
 { 
  x=vc[i].first; 
  y=vc[i].second; 
  if(x!=r)
  { 
   cout << x; 
   r=x; 
  } 
  else 
  { 
   cout << y; 
   r=y; 
  } 
  cout << ' '; 
 } 

 return 0;

}
