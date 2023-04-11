class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    bool static comp(Item a, Item b){
        double r1=((double)a.value/(double)a.weight);
        double r2=((double)b.value/(double)b.weight);
        return r1>r2;
    }
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        double finalValue=0.0;
        int curWeight=0;
        for(int i=0;i<n;i++){
            if(curWeight+arr[i].weight <=w){
                curWeight+=arr[i].weight;
                finalValue+=arr[i].value;
            }else{
                int remain=w-curWeight;
                finalValue+=(arr[i].value/(double)arr[i].weight)*(double)remain;
                break;
            }
        }
        return finalValue;
    }
        
};
