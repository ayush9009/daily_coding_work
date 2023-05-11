
class Solution {
public:
    //Buddhi khrb karne vala question lakin badiya question
    //Here we use aaporach meet in the middle
    // we divide the array into two halfves
    // left and right,left size (0,n-1) right (n,2*n-1) 
    // now suppose we left subset have size =sz therefore right subset size=n-sz
    // suppse from left half we get sum=s1 and from right half we get sum =s2
    // so we want that abs(s2-s1)=minium 
    // therefore s2=total sum of array -s1 means s2=sum-s1
    // therefore sum-s1-s1 means we have to minimise sum-2s1.
    // we have get  sum=s1 from leftsubset to we can binary search the s2 sum in right half
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;
        sum = accumulate(nums.begin(), nums.end(),0);
        
        int N = n/2;
        vector<vector<int>> left(N+1), right(N+1);
        
		//storing all possible sum in left and right part
        for(int mask = 0; mask<(1<<N); ++mask){
            int sz = 0, l = 0, r = 0;
            for(int i=0; i<N; ++i){
                if(mask&(1<<i)){
                    sz++;
                    l += nums[i];
                    r += nums[i+N];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        for(int sz=0; sz<=N; ++sz){
            sort(right[sz].begin(), right[sz].end());
        }

        res = min(abs(sum-2*left[N][0]), abs(sum-2*right[N][0]));

		//iterating over left part
        for(int sz=1; sz<N; ++sz){
            for(auto &a : left[sz]){
                int b = (sum - 2*a)/2, rsz = N-sz;
                auto &v = right[rsz];
                auto itr = lower_bound(v.begin(), v.end(),b); //binary search over right part
                
                if(itr!=v.end()) res = min(res, abs(sum-2*(a+(*itr))));
                if(itr!= v.begin()){
                    auto it = itr; --it;
                    res = min(res, abs(sum-2*(a+(*it))));
                }                
            }
        }
        return res;
        
    }
};
