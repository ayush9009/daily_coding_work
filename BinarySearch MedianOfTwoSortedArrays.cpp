class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     for(int i=0;i<nums2.size();i++)
    //     {
    //         nums1.push_back(nums2[i]);
    //     }
    //     sort(nums1.begin(),nums1.end());
    // int m;
    // double r;
    // if(nums1.size()%2!=0){
    //  m=nums1.size()/2;
    //  r=nums1[m]*1.0;
    // }
    // else{
    //     m=nums1.size()/2;
    //     r=(nums1[m]+nums1[m-1])/2.0;
    // }
    // return r;
    // }
    for(int i=0;i<nums2.size();i++){
        nums1.push_back(nums2[i]);
    }
    sort(nums1.begin(),nums1.end());
    int m;
    double r;
    if(nums1.size()%2!=0){
        m=nums1.size()/2;
        r=nums1[m]*1.0;
    }else{
        m=nums1.size()/2;
        r=(nums1[m]+nums1[m-1])/2.0;
    }
    return r;
    }
};
