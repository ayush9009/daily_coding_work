class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // // sort(intervals.begin(),intervals.end());
        // int n=intervals.size();
        // vector<int>ans;
        // for(int i=0;i<intervals.size();i++){
        //     int mid=intervals[i][1];
        //     int l=0,r=n-1;
        //     vector<int>result;
        //     while(l<=r){
        //         if(intervals[l][0]>=mid)
        //         {
        //             result.push_back(l);
        //             r--;
        //             break;
        //         }else{
        //             l++;
        //         }
        //     }
        //     if(result.size()==0)ans.push_back(-1);
        //     else ans.push_back(result[0]);
        // }
        // return ans;
        map<int,int>mp;
        for(int i=0;i<intervals.size();i++){
            mp.insert({intervals[i][0],i});
        }

        vector<int>ans;

        for(int i=0;i<intervals.size();i++){
            auto it=mp.lower_bound(intervals[i][1]);
            (it!=mp.end())?ans.push_back(it->second):ans.push_back(-1);
        }
        return ans;
    }
};
