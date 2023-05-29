class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //deko dequeu mai index push kar rai,agr window out of bound jari i.e i-k to pop kardo front se
        //aur agr jo hum next greater dek rai using deque back se ,agr nums[dq.back()]<nums[i] to pop
        //means 3 1 -1 hai -1<4 to -1 ki jarot ni h pop kar do
        //front se index pop kar rai,back se smaller elements
        //aur agr i>=k-1 to push anser front mai maximum hai 
        deque<int>dq;
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            // i-k?
            //  0 1 2 3 4
            //  dq front=0 k=3
            //  aur aapka i aa chuka 3 pai yani aapki window size=4
            //  to i-k check karo i.e 3-3=0 that is equal to dq.front() so pop out dq.front()
            if(dq.empty()==false && dq.front()==i-k)dq.pop_front(); //ye kar rai outofbound mintain kaliye
            while(dq.empty()==false && nums[dq.back()]<nums[i]){
                dq.pop_back();  //jo element kaam ka ni use pop kar do
            }
            dq.push_back(i);  //push kar rai index in dq vo bhi back mai kuki front mai max value indx h
            if(i>=k-1)result.push_back(nums[dq.front()]);
            //   0 1 2 3 k=3 aur aap ho i=2 pai to 0 vala front
            // to ans.push dq.front() 
        }
        return result;
    }
};
