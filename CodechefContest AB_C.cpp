#include <bits/stdc++.h>
using namespace std;

void singh(){
    return;
}
void tingo(long long no_elemen){
    cout<<(no_elemen/1000000)-1<<" "<<1000000<<" "<<1000000<<endl; 
}
void helo(){
    return;
}
void singo(long long no_elemen){
     cout<<(no_elemen/1000000)<<" "<<1000000<<" "<<no_elemen%1000000<<endl;
}
bool sata(string p, string s) {
        vector<string> v;
        stringstream ss(s);
        string str;
        
        while(ss >> str)
            v.push_back(str);
        
        if(p.size() != v.size()) return false;
     
        unordered_map<char, int> mp1;
        unordered_map<string, int> mp2;
        
        for(int i=0; i<p.size(); i++)
        {
            if(mp1[p[i]] != mp2[v[i]]) return false;
            
            mp1[p[i]] = i+1;
            mp2[v[i]] = i+1;
        }

        return true;

     
//         vector<string>v;
//         stringstream ss(s);
//         string str;
//         while(ss>>str){
//             v.push_back(str);
//         }
//         if(p.size()!=v.size())return false;
//         unordered_map<char,int>mp1;
//         unordered_map<string,int>mp2;
//         for(int i=0;i<p.size();i++){
//             if(mp1[p[i]]!=mp2[v[i]])return false;
            
//             mp1[p[i]]=i+1;
//             mp2[v[i]]=i+1;
//         }
//         return true;
}
void helper(){
    long long no_elemen;
    cin>>no_elemen; 
    singh();
    if(no_elemen==1){ 
        singh();
        cout<<-1<<endl;return; 
    } 
    if(no_elemen<=1000000){ 
        singh();
        cout<<1<<" "<<1<<" "<<no_elemen-1<<endl; 
        singh();
    } 
    else if(no_elemen%1000000==0){ 
        singh();
        tingo(no_elemen);
        singh();
    } 
    else{ 
        singh();
       singo(no_elemen); 
       singh();
    }
    singh();
}
int main() {
	// your code goes here
	int t;
	singh();
	cin>>t;
	singh();
	while(t--){
	    
	   // for(long long i=0;i<=x/2;i++){
	   //     for(long long j=0;j<=x/2;j++){
	   //         for(long long k=0;k<=x/2;k++){
	   //             if(i*j+k==x){
	   //                 cout<<i<<" "<<j<<" "<<k<<endl;
	   //                 flag=1;
	   //                 break;
	   //             }
	   //         }
	   //         if(flag)break;
	   //     }
	   //     if(flag)break;
	   // }
	   // if(flag==0)cout<<-1<<endl;
	   singh();
	  helper();
	}
	return 0;
}
