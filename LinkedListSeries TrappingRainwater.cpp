class Solution {
public:
    int trap(vector<int>& height) {
        // brute force- min(leftmax,rightmax)-height[partcialr index]
        //better apporach- left array as prefix array right array as suffix array then apply above 
        // formula you get anser but time complexityO(n) space compl - O(2n)
        //optimised apporach left pointer right pointer O(n) space compl-O(1)
        // int n=height.size();
        // int left[n],right[n];
        // left[0]=height[0];
        // for(int i=1;i<n;i++)
        //     left[i]=max(left[i-1],height[i]);
        // right[n-1]=height[n-1];
        // for(int i=n-2;i>=0;i--)
        //     right[i]=max(right[i+1],height[i]);
        // for(int i=0;i<n;i++)cout<<left[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<right[i]<<" ";
        // cout<<endl;
        // int water=0;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<(min(left[i],right[i])-height[i]);
        //     water+=(min(left[i],right[i])-height[i]);
        // }
        // return water;

        //optimised apporach-pointer aporach
        // int left=0,right=height.size()-1;
        // int leftmax=0,rightmax=0;
        // int ans=0;
        // while(left<=right){
        //     if(height[left]<=height[right]){
        //         if(leftmax<=height[left])leftmax=height[left];
        //         else ans+=leftmax-height[left];
        //         left++;
        //     }else{
        //         if(rightmax<=height[right])rightmax=height[right];
        //         else ans+=rightmax-height[right];
        //         right--;
        //     }
        // }
        // return ans;
        int left=0,right=height.size()-1;
        int leftmax=0,rightmax=0;
        int ans=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(leftmax<=height[left])leftmax=height[left];
                else ans+=leftmax-height[left];
                left++;
            }else{
                if(rightmax<=height[right])rightmax=height[right];
                else ans+=rightmax-height[right];
                right--;
            }
        }
        return ans;
    }
};
