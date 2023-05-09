void insert(stack<int>&s,int temp){
    if(s.size()==0 || s.top()<=temp){
        s.push(temp);
        return;
    }
    int val=s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
    return;
}
void SortedStack :: sort()
{
   //Your code here
   
//   if(s.size()==1)return;
//   int temp=s.top();
//   s.pop();
//   insert(s,temp);
//   return;
    vector<int>result;
	while(s.empty()==false){
		result.push_back(s.top());
		s.pop();
	}
	for(int i=0;i<result.size();i++){
	   
	    for(int j=i+1;j<result.size();j++){
	        int temp=0;
	        if(result[i]<result[j]){
	            temp=result[j];
	            result[j]=result[i];
	            result[i]=temp;
	           // arr[j]=temp;
	        }
	    }
	   // result[i]=temp;
	}
// 	sort(result.begin(),result.end(),greater<int>());
	reverse(result.begin(),result.end());
	for(int i=0;i<result.size();i++){
		
		s.push(result[i]);
	}
}
