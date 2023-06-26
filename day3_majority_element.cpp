////CODESTUDIO 
/*Time Complexity: O(n log n + n)
Auxiliary Space: O(1)
*/
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int count=0;
	sort(arr,arr+n);/////o(nogn)
	int r=arr[n/2];
	for(int i=0;i<n;i++){
		if(arr[i]==r){
			count=count+1;
		}
	}
	if(count>(n/2))return r;
	else return -1;
}



/*  OPTIMAL APPROACH 
Moore's voting algorithm
TC=O(2n)
SC=O(1)
*/

#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Moore's voting algorithm
	//count the presence of element 
	  int count=0;
	  int mele;
	  for(int i=0;i<n;i++){
		  if(count==0){
			  count=1;
			  mele=arr[i];
		  }
		  else if(arr[i]==mele)
			  count++;
		  
		  else
			  count--;
		  }
	int  fc=0;
	  for(int i=0;i<n;i++){
		  if(arr[i]==mele)
		   fc++;
	}
	if(fc>n/2)return mele;
	else return -1;
	
}


///LEETCODE
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         return nums[nums.size()/2];
    }
   
};



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int value;
        int max=INT_MIN;
        for(auto in : mp){
            if(in.second>max){
            max=in.second;
            value =in.first;
            }
           
        }
        return value;
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(ans==nums[i]){
               count++;
            }
            else if(ans!=nums[i]){
                count--;
              
                if(count==0){
                   count++;
                   ans=nums[i];
                }
            }
            // cout<<ans<<" ";
        }
        return ans;
    }
};
