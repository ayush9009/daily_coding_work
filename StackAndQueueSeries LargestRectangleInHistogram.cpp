
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long>st;
        long long leftSmall[n],rightSmall[n];
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
        
        if(st.empty())leftSmall[i]=0;  //0 hogi boundary
        else leftSmall[i]=st.top()+1;  //kuki aap agey ki taraf badh rai na
        st.push(i);
        }
        
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            if(st.empty())rightSmall[i]=n-1; //n-1 hogi boundary
            else rightSmall[i]=st.top()-1;  //kuki aap array mai peechey ki taraf arey
            
            st.push(i);
        }
        long long maxAns=0;
        for(int i=0;i<n;i++){
            maxAns=max(maxAns,arr[i]*(rightSmall[i]-leftSmall[i]+1));
        }
        return maxAns;
    }
};
