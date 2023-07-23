//methtod1
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(auto in:nums1)
        ans.push_back(in);
        for(auto in:nums2)
        ans.push_back(in);
        sort(ans.begin(),ans.end());
        int r=ans.size();
        if(r%2!=0){
            int x=r/2;
            double an=(double)ans[x];
            return an;
        }
        else {
            int x=r/2;
            int y=x-1;
            double an=(ans[x]+ans[y])/2.00000;
            return an;
        }
        return 1.000000;
    }
};
//method2
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n1=nums1.size();
        int n2=nums2.size();
        int r1=0,r2=0;
    
        while(r1!=n1 && r2!=n2){
            if(nums1[r1]>nums2[r2]){
              ans.push_back(nums2[r2]);
              r2++;
            }
            else {
                 ans.push_back(nums1[r1]);
               r1++;
            }
        }
        while(r1!=n1){
         ans.push_back(nums1[r1]);
         r1++;
        }
        while(r2!=n2){
           ans.push_back(nums2[r2]);
           r2++;
        }
       int x=ans.size();
       if(x%2==0){//even
       double x1=ans[x/2];
       double x2=ans[(x/2)-1];
        double ans1=(x1+x2)/2.00000;
        return ans1;
       }
       else{
           return (double)ans[ans.size()/2];
       }
       return -1;
    }
};


/*TC =O(log(min(n1,n2))
  SC=O(1)
  */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     
        if(nums2.size()<nums1.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
           int n1=nums1.size();
        int n2=nums2.size();
   int low=0;
   int high=n1;
   while(low<=high){
   int cnt1=(low+high)/2;
   int cnt2=(n1+n2+1)/2-cnt1;
   ///now give values to l1 ,l2,r1,r2;
  int l1=(cnt1!=0)?nums1[cnt1-1]:INT_MIN;
  int l2=(cnt2!=0)?nums2[cnt2-1]:INT_MIN;
  int r1=(cnt1!=n1)?nums1[cnt1]:INT_MAX;
  int r2=(cnt2!=n2)?nums2[cnt2]:INT_MAX;
 if(l1<=r2 && l2<=r1){
  if((n1+n2)%2==0)
  return (max(l1,l2)+min(r1,r2))/2.0;
  else 
  return max(l1,l2);
 }
else if(l1>r2){
high=cnt1-1;
}
else{
low=cnt1+1;
}
}
return 0.0;
}
};
