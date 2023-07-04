/*BRUTE FORCE APPROACH
  TC=O(n^2)
  SC=O(1)
  */
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
          for(int j=i+1;j<nums.size();j++){
          long long x1=nums[i];
          long long x2=nums[j];
          if(x1>2*x2)count++;
       
          }
        }
        return count;
    }
};
/*OPTIMAL APPROACH
TC=O(2nlogn)
SC=O(n)
DISTORTING THE ARRAY !!
array positioning is changed from unsorted to sorted as we are applying MERGE SORT in this case.
*/
#include <bits/stdc++.h> 

void so(vector<int>&arr,int low,int mid,int high){
	int left=low;
	int right=mid+1;
	vector<int>temp;
	while(left<=mid && right<=high){
     if(arr[left]>arr[right]){
		 temp.push_back(arr[right]);
		 right++;
	 }
	 else{
		 temp.push_back(arr[left]);
		 left++;
	 }
	}
	while(left<=mid){
         temp.push_back(arr[left]);
		 left++;
	}
	while(right<=high){
     	 temp.push_back(arr[right]);
		 right++;
	}
	//for loop
	for(int i=low;i<=high;i++){
		arr[i]=temp[i-low];
	}


	
}
int CountPair(vector<int>&arr,int low,int mid,int high){
int right=mid+1;
int cnt=0;
for(int i=low;i<=mid;i++){
	while(right<=high && arr[i]>2*arr[right])right++;
	cnt+=(right-(mid+1));

}
return cnt;
}
int ms(vector<int>&arr,int low,int high){
	int  cnt=0;
	if(low>=high)return cnt;//return 0
	int mid=(low+high)/2;
	cnt+=ms(arr,low,mid);
	cnt+=ms(arr,mid+1,high);
	cnt+=CountPair(arr,low,mid,high);
	so(arr,low,mid,high);
   return cnt;
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	return ms(arr,0,n-1);

}
