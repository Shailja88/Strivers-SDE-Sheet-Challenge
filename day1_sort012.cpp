//codestudio
include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   
  int low=0,mid=0,high=n-1;
  while(mid<=high){
  if(arr[mid]==0){
   swap(arr[mid],arr[low]);
   low++,mid++;
  }
  else if(arr[mid]==1){
   mid++;
  }
   else{
       swap(arr[mid],arr[high]);
   high--;
    }
  }

}
//leetcode
class Solution {
public:
    void sortColors(vector<int>& nums) {
        ////dutch national flag
        int x=nums.size();
        int low=0,high=x-1,mid=0;  
           while(high>=mid){
        if(nums[mid]==0){
          swap(nums[low],nums[mid]);
          low++,mid++;
        }
         else if(nums[mid]==1){
          mid++;
        } 
        else{
          swap(nums[mid],nums[high]);
          high--;
        }
           }
    }
};
