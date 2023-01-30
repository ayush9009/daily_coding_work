
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>result;
		    int n=s.size();
		  //  1<<n is similar to 2^n (2ki power n)
		    for(int i=0;i<(1<<n);i++){
		        string str="";
		        for(int j=0;j<n;j++){
		            if(i&(1<<j)){
		                str+=s[j];
		            }
		        }
		        if(str.size()>0)
		        result.push_back(str);
		    }
         //sort isliye kuki answer lexicographically sorted chaiye
		        sort(result.begin(),result.end());  
		    	return result;
		}
	
};
