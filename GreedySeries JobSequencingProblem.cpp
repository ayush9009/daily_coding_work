class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    bool static comparison(Job a,Job b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    {  
        //greedy:ki bhai jo sabse jada profit hai pahle vo job karo to isliye we sort arr in descending order of
        // profit
        //intution:the job with the given deadline perform on the dealdine
        //mtlb ek job aap is job ko 5 tarik tak kar sako yani 5 tarik is last day,
        // to hum us job 5 tarik ko hi karenge to jo shuru kai din ya time unme hum koi aur job bhi kar sake
        // to gain maximum profit
        //to inmiitalyy jiski dealdine sabse jada utne size ka array ko -1 se set kar do
        sort(arr,arr+n,comparison);  //sorrting in descending order of profit
        int maxi=arr[0].dead;
        for(int i=1;i<n;i++){
            maxi=max(maxi,arr[i].dead); //maximum dealdine kya vo find kar rai
        }
        int slot[maxi+1];
        for(int i=0;i<=maxi;i++){
            slot[i]=-1;//assign -1 to every element
        }
        int countJobs=0,jobProfit=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){//j=arr[i].dead mtlb agr dealine =5 th day to j=5
                if(slot[j]==-1){ //yani aap is din job perform kar sako
                    slot[j]=i; //to 5th day hum i job perform kar rai
                    countJobs++;//job perform hori conunt++ 
                    jobProfit+=arr[i].profit;//aur profit bhi set kar diya
                    break;
                }
            }
        }
    vector<int>result;
    result.push_back(countJobs);
    result.push_back(jobProfit);
    return result;
    } 
